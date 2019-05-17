// sfmltest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Player.h"





int _tmain(int argc, _TCHAR* argv[])
{

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


	//const sf::String s = "XD";
	//sf::Font font;
	//font.loadFromFile(FONT_PATH);

	//sf::Text text(s,font);
	//text.setPosition(100, 100);

	//sf::RectangleShape shape(sf::Vector2f(50,50));
	//shape.setPosition(sf::Vector2f(10, 10));
	//shape.setFillColor(sf::Color::Transparent);
	//shape.setOutlineColor(sf::Color::Yellow);
	//shape.setOutlineThickness(1.f);
	//sf::RectangleShape txtshape(sf::Vector2f(text.getLocalBounds().width,text.getLocalBounds().height));
	//txtshape.setPosition(text.getPosition());
	//txtshape.setFillColor(sf::Color::Transparent);
	//txtshape.setOutlineColor(sf::Color::Red);
	//txtshape.setOutlineThickness(1.f);

	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);


	sf::RenderWindow window(sf::VideoMode(600, 600), "Window", sf::Style::Fullscreen);
	MenuWindow menu(window);
	/*Map o1 = Map(window, sf::Vector2f(0, 0), sf::Vector2f(750, 50));*/
	std::vector<Map> map = Map::stage1(window);

	////!!!!!!!!!!!!!!!niekoniecznie to stosowac, albo znalezc fajne t³o xd
	//sf::Texture gameBackgroundTexture;
	//assert(gameBackgroundTexture.loadFromFile("./sprites/game_background.png"));
	//gameBackgroundTexture.setRepeated(true);
	//sf::Sprite gameBackground;
	//gameBackground.setColor(sf::Color::Blue);
	//gameBackground.setTexture(gameBackgroundTexture);
	//gameBackground.setTextureRect(sf::IntRect(0, 0, 2000, 1090));

	sf::Event event;
	Player pl(window, "./sprites/player.png",sf::Vector2f(MAP_OFFSET_X + 9 * MAP_PIXELS_SIZE,MAP_OFFSET_Y + 14 * MAP_PIXELS_SIZE));

	while (window.isOpen())
	{
		//window.draw(shape);
		//window.draw(text);
		//window.draw(shape);
		//window.draw(txtshape);

		//Menu Window test
		//menu.draw(window);
		//menu.setStatus(window);
		//menu.checkStatus(window, event);

		//Player test
		window.clear();
		//window.draw(gameBackground);
		for (auto& obj : map) {
			obj.draw(window);
			if (pl.doesCollide(obj.getShape()))
				pl.stop();
		}
		pl.update(window,event,map);
		//pl.getStates();
		
		pl.draw(window);



		window.display();
	}

	return 0;
}

