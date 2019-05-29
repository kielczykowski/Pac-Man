#include "stdafx.h"
#include "MenuWindow.h"


MenuWindow::MenuWindow(sf::RenderWindow &window)
{
	//View Problem
	//menuView = sf::View(sf::FloatRect(0, 0, BACKGROUND_MENU_WIDTH, BACKGROUND_MENU_HEIGHT));
	//window.setView(menuView);

	//sf::Vector2f wordlPos = window.mapPixelToCoords(sf::Vector2i(window.getSize().x,window.getSize().y));

	assert(background_texture_.loadFromFile("./sprites/backgroundXD.png"));

	background_texture_.setSmooth(true);
	background_.setColor(sf::Color::Magenta);
	background_.setTexture(background_texture_);
	//background.setColor(sf::Color(255, 255, 255, 200));


	assert(font_.loadFromFile(FONT_PATH));

	game_name_.setString("Mechatronman");
	game_name_.setFont(font_);
	game_name_.setCharacterSize(150);
	game_name_.setStyle(sf::Text::Bold);
	game_name_.setFillColor(sf::Color::White);
	game_name_.setPosition(0.2 * static_cast<double>(window.getSize().x), 0.1 * static_cast<double>(window.getSize().y));

	for (auto& obj : options_) {
		obj.setFont(font_);
		obj.setStyle(sf::Text::Bold);
		obj.setFillColor(sf::Color::White);
		obj.setCharacterSize(100);
	}

	options_[0].setString("Play");
	options_[0].setPosition(0.2 * static_cast<double>(window.getSize().x), 0.4 *static_cast<double>(window.getSize().y));

	options_[1].setString("Highscores");
	options_[1].setPosition(0.2 * static_cast<double>(window.getSize().x), 0.5 * static_cast<double>(window.getSize().y));

	options_[2].setString("Exit");
	options_[2].setPosition(0.2 * static_cast<double>(window.getSize().x), 0.6 * static_cast<double>(window.getSize().y));



}


MenuWindow::~MenuWindow()
{
}

void MenuWindow::draw(sf::RenderWindow &window) const{
	window.clear();
	window.draw(background_);
	window.draw(game_name_);
	for (int i = 0; i < 3; i++) {
		window.draw(options_[i]);
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
		if (window.getPosition().x + options_[i].getPosition().x <= sf::Mouse::getPosition().x && window.getPosition().x + options_[i].getPosition().x + options_[i].getLocalBounds().width >= sf::Mouse::getPosition().x &&
			window.getPosition().y + options_[i].getPosition().y <= sf::Mouse::getPosition().y && window.getPosition().y + options_[i].getPosition().y + options_[i].getLocalBounds().height >= sf::Mouse::getPosition().y) {
			options_[i].setFillColor(sf::Color::Red);
		}
		else {
			options_[i].setFillColor(sf::Color::White);
		}
	}

	//Keyboard dependent
}

int MenuWindow::getStatus() const{
	for (int i = 0; i < 3; i++) {
		if (options_[i].getFillColor() == sf::Color::Red)
			return i;
	}
	return -1;
}

void MenuWindow::checkStatus(sf::RenderWindow&window, sf::Event& event, GameMaster& game, Highscore& hgh) const{
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::MouseButtonPressed:
			switch (event.key.code){
			case sf::Mouse::Left:
				switch (getStatus()) {
				case 0:
					std::cout << "Play" << std::endl;
					game.main(window, event,hgh);
					break;
				case 1:
					std::cout << "Highscore" << std::endl;
					hgh.main(window,event);
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
