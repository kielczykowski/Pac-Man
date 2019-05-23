#include "stdafx.h"
#include "MenuWindow.h"


MenuWindow::MenuWindow(sf::RenderWindow &window)
{
	//View Problem
	//menuView = sf::View(sf::FloatRect(0, 0, BACKGROUND_MENU_WIDTH, BACKGROUND_MENU_HEIGHT));
	//window.setView(menuView);

	//sf::Vector2f wordlPos = window.mapPixelToCoords(sf::Vector2i(window.getSize().x,window.getSize().y));

	assert(background_texture.loadFromFile("./sprites/backgroundXD.png"));

	background_texture.setSmooth(true);
	background.setColor(sf::Color::Magenta);
	background.setTexture(background_texture);
	//background.setColor(sf::Color(255, 255, 255, 200));


	assert(font.loadFromFile(FONT_PATH));

	gameName.setString("Mechatronman");
	gameName.setFont(font);
	gameName.setCharacterSize(150);
	gameName.setStyle(sf::Text::Bold);
	gameName.setFillColor(sf::Color::White);
	gameName.setPosition(0.2 * static_cast<double>(window.getSize().x), 0.1 * static_cast<double>(window.getSize().y));

	options[0].setFont(font);
	options[2].setFont(font);
	options[1].setFont(font);

	options[0].setStyle(sf::Text::Bold);
	options[1].setStyle(sf::Text::Bold);
	options[2].setStyle(sf::Text::Bold);

	options[0].setString("Play");
	options[0].setFillColor(sf::Color::White);
	options[0].setCharacterSize(100);
	options[0].setPosition(0.2 * static_cast<double>(window.getSize().x), 0.4 *static_cast<double>(window.getSize().y));

	options[1].setString("Highscores");
	options[1].setFillColor(sf::Color::White);
	options[1].setCharacterSize(100);
	options[1].setPosition(0.2 * static_cast<double>(window.getSize().x), 0.5 * static_cast<double>(window.getSize().y));

	options[2].setString("Exit");
	options[2].setFillColor(sf::Color::White);
	options[2].setCharacterSize(100);
	options[2].setPosition(0.2 * static_cast<double>(window.getSize().x), 0.6 * static_cast<double>(window.getSize().y));

	

}


MenuWindow::~MenuWindow()
{
}

void MenuWindow::draw(sf::RenderWindow &window) {
	window.clear();
	window.draw(background);
	window.draw(gameName);
	for (int i = 0; i < 3; i++) {
		window.draw(options[i]);
	}
	//window.setView(menuView);
}

void MenuWindow::setStatus(sf::RenderWindow& window) {
	//Mouse dependent - not fully working 

	for (int i = 0; i < 3; i++) {
		//std::cout << options[i].getGlobalBounds().left << std::endl;
		//std::cout << options[i].getGlobalBounds().top << std::endl;
		//std::cout << options[i].getGlobalBounds().height << std::endl;
		//std::cout << options[i].getGlobalBounds().width << std::endl;
		if (window.getPosition().x + options[i].getPosition().x <= sf::Mouse::getPosition().x && window.getPosition().x + options[i].getPosition().x + options[i].getLocalBounds().width >= sf::Mouse::getPosition().x &&
			window.getPosition().y + options[i].getPosition().y <= sf::Mouse::getPosition().y && window.getPosition().y + options[i].getPosition().y + options[i].getLocalBounds().height >= sf::Mouse::getPosition().y) {
			options[i].setFillColor(sf::Color::Red);
		}
		else {
			options[i].setFillColor(sf::Color::White);
		}
	}

	//Keyboard dependent
}

int MenuWindow::getStatus() {
	for (int i = 0; i < 3; i++) {
		if (options[i].getFillColor() == sf::Color::Red)
			return i;
	}
	return -1;
}

void MenuWindow::checkStatus(sf::RenderWindow&window, sf::Event& event, GameMaster& game) {
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::MouseButtonPressed:
			switch (event.key.code){
			case sf::Mouse::Left:
				switch (getStatus()) {
				case 0:
					std::cout << "Play" << std::endl;
					game.main(window,event);
					break;
				case 1:
					std::cout << "Highscore" << std::endl;
					break;
				case 2:
					std::cout << "Exit" << std::endl;
					window.close();
					break;
				case -1:
					break;
				}
				break;
			}
		}
	}
}
