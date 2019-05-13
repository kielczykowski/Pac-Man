// sfmltest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MenuWindow.h"





int _tmain(int argc, _TCHAR* argv[])
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Window");
	//sf::Texture background_texture;
	//sf::Sprite background;
	//sf::View menuView(sf::FloatRect(0, 0, BACKGROUND_MENU_WIDTH, BACKGROUND_MENU_HEIGHT));
	//sf::Text gameName; sf::Font gameNameFont;

	//assert(gameNameFont.loadFromFile(FONT_PATH));
	//assert(background_texture.loadFromFile("./sprites/background.jpg"));

	//background_texture.setSmooth(true);
	//background.setColor(sf::Color::Magenta);
	//background.setTexture(background_texture);

	//gameName.setString("Mechatronman");
	//gameName.setFont(gameNameFont);
	//gameName.setCharacterSize(350);
	//gameName.setStyle(sf::Text::Bold);
	//gameName.setFillColor(sf::Color::Black);
	//gameName.setPosition(0.2 * window.getSize().x,0.1 * window.getSize().y);
	//
	//

	//window.setView(menuView);
	//window.setFramerateLimit(60);

	MenuWindow menu(window);





	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		menu.draw(window);

	}

	return 0;
}

