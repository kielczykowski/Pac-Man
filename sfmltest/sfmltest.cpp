// sfmltest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MenuWindow.h"






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

	//sf::CircleShape square(80, 4);
	//square.setFillColor(sf::Color::Blue);
	//square.setPosition(150, 150);
	////square.setOrigin(40.f, 40.f);
	//square.rotate(45.f);


	sf::RenderWindow window(sf::VideoMode(600, 600), "Window", sf::Style::Fullscreen);
	MenuWindow menu(window);
	GameMaster game;
	sf::Event event;

	/*Map o1 = Map(window, sf::Vector2f(0, 0), sf::Vector2f(750, 50));*/
	//std::vector<Map> map = Map::stage1(window);
	//std::vector<Point> points = Point::stage1();

	////mask for teleport
	//std::vector<Map> mask{		Map(window, sf::Vector2f(17 * MAP_PIXELS_SIZE, 9 * MAP_PIXELS_SIZE), sf::Vector2f(2 * MAP_PIXELS_SIZE, MAP_PIXELS_SIZE), sf::Color::Black),
	//							Map(window, sf::Vector2f(0, 9 * MAP_PIXELS_SIZE), sf::Vector2f(2 * MAP_PIXELS_SIZE, MAP_PIXELS_SIZE), sf::Color::Black) };

	////teleport 
	//std::vector<Map> teleport{	Map(window, sf::Vector2f(-2 * MAP_PIXELS_SIZE, 9 * MAP_PIXELS_SIZE), sf::Vector2f(MAP_PIXELS_SIZE, MAP_PIXELS_SIZE), sf::Color::White),
	//							Map(window, sf::Vector2f(19 * MAP_PIXELS_SIZE, 9 * MAP_PIXELS_SIZE), sf::Vector2f(MAP_PIXELS_SIZE, MAP_PIXELS_SIZE), sf::Color::White) };


	//if (points[points.size() - 1].getPower() == SpecialPower::SLOW_EAT_ENEMY) {
	//	std::cout << " sloweat enemy" << std::endl;
	//}

	//SpecialPoint sp = SpecialPoint(sf::Vector2f(150, 150));

	////!!!!!!!!!!!!!!!niekoniecznie to stosowac, albo znalezc fajne t³o xd
	//sf::Texture gameBackgroundTexture;
	//assert(gameBackgroundTexture.loadFromFile("./sprites/game_background.png"));
	//gameBackgroundTexture.setRepeated(true);
	//sf::Sprite gameBackground;
	//gameBackground.setColor(sf::Color::Blue);
	//gameBackground.setTexture(gameBackgroundTexture);
	//gameBackground.setTextureRect(sf::IntRect(0, 0, 2000, 1090));


	//Player pl(window, "./sprites/player.png",sf::Vector2f(MAP_OFFSET_X + 9 * MAP_PIXELS_SIZE,MAP_OFFSET_Y + 14 * MAP_PIXELS_SIZE));

	//sf::Clock clock;
	////sf::Time accumulator = sf::Time::Zero;
	////sf::Time ups = sf::seconds(1.f / 60.f);
	//float delta=0.0015f;
	//float nextTime = clock.getElapsedTime().asSeconds();
	while (window.isOpen())
	{

		
		//window.draw(shape);
		//window.draw(text);
		//window.draw(shape);
		//window.draw(txtshape);

		//Menu Window test
		menu.draw(window);
		menu.setStatus(window);
		menu.checkStatus(window, event,game);

		//Player test
//		float currTime = clock.getElapsedTime().asSeconds();
//		if (currTime >= nextTime) {
//			nextTime += delta;
//			window.clear();
//			//window.draw(gameBackground);
//
//			
//			//map drawing
//			for (auto& obj : map) {
//				obj.draw(window);
//				if (pl.doesCollide(obj.getShape()))
//					pl.stop();
//			}
//
//			//teleport handling
//			if (pl.doesCollide(teleport[0].getShape())){
//				pl.setPosition(18.f, 9.f);
//				pl.setmoveLeft();
//			}
//			else if (pl.doesCollide(teleport[1].getShape())) {
//				pl.setPosition(0.f, 9.f);
//				pl.setmoveRight();
//			}
//
//			//points on canvas + handling
//			for (auto it = points.begin(); it < points.end();) {
//
//				if (pl.doesCollide(it->getShape())) {
//					it = points.erase(it);
//					//add points to player
//				}
//				else {
//					it->draw(window);
//					++it;
//				}
//
//			}
//			//player actions
//
//
//			//sp.draw(window);
//			pl.update(window, event, map);
//			//pl.getStates();
//
//			pl.draw(window);
//			//Mask for teleport
//			mask[0].draw(window);
//			mask[1].draw(window);
//		}
//		else{
//			int sleepTime = (int)(1000.0 * (nextTime - currTime));
//			if (sleepTime > 0) {
//				Sleep(sleepTime);
//			}
//		}
//
//		//while (accumulator > ups) {
//		//	accumulator -= ups;
//		//}
//
//
//
		window.display();
////		accumulator += clock.restart();
	}

	return 0;
}

