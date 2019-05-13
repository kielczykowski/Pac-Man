#include "stdafx.h"
#include "MenuWindow.h"


MenuWindow::MenuWindow(sf::RenderWindow &window)
{

	assert(background_texture.loadFromFile("./sprites/background.jpg"));

	background_texture.setSmooth(true);
	//background.setColor(sf::Color::Magenta);
	background.setTexture(background_texture);
	background.setColor(sf::Color(255, 255, 255, 200));


	assert(font.loadFromFile(FONT_PATH));

	gameName.setString("Mechatronman");
	gameName.setFont(font);
	gameName.setCharacterSize(350);
	gameName.setStyle(sf::Text::Bold);
	gameName.setFillColor(sf::Color::Black);
	gameName.setPosition(0.2 * window.getSize().x, 0.1 * window.getSize().y);

	options[0].setFont(font);
	options[2].setFont(font);
	options[1].setFont(font);

	options[0].setStyle(sf::Text::Bold);
	options[1].setStyle(sf::Text::Bold);
	options[2].setStyle(sf::Text::Bold);

	options[0].setString("Play");
	options[0].setFillColor(sf::Color::Red);
	options[0].setCharacterSize(200);
	options[0].setPosition(0.2 * static_cast<float>(window.getSize().x), 1.0 * static_cast<float>(window.getSize().y));

	options[1].setString("Highscores");
	options[1].setFillColor(sf::Color::Black);
	options[1].setCharacterSize(200);
	options[1].setPosition(0.2 * static_cast<float>(window.getSize().x), 1.5 * static_cast<float>(window.getSize().y));

	options[2].setString("Exit");
	options[2].setFillColor(sf::Color::Black);
	options[2].setCharacterSize(200);
	options[2].setPosition(0.2 * static_cast<float>(window.getSize().x), 2.0 * static_cast<float>(window.getSize().y));

	menuView = sf::View(sf::FloatRect(0, 0, BACKGROUND_MENU_WIDTH, BACKGROUND_MENU_HEIGHT));
}


MenuWindow::~MenuWindow()
{
}

void MenuWindow::draw(sf::RenderWindow &window) {
	window.clear();
	window.setView(menuView);
	window.draw(background);
	window.draw(gameName);
	for (int i = 0; i < 3; i++) {
		window.draw(options[i]);
	}
	window.display();
}
