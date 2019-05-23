#include "stdafx.h"
#include "GameMaster.h"


void GameMaster::updateScore(int&& value){
	if (value < 0) {
		if (score - value < 0)
			score = 0;
		else 
			score += value;
	}
	else
		score += value;
}

void GameMaster::updateLifes(int&& value){
	if (value < 0) {
		if (lifes - value < 0)
			lifes = 0;
		else
			lifes += value;
	}
	else
		lifes += value;
}

bool GameMaster::isDead(){
	if (lifes <= 0) {
		return true;
	}
	else
		return false;
}
void GameMaster::init(){
	score = 0;
	lifes = 3;
	exit = false;
	pause = false;
}

bool GameMaster::getPause(){
	return pause;
}
bool GameMaster::getExit(){
	return score;
}


GameMaster::GameMaster()
{
	init();
}


GameMaster::~GameMaster()
{
}

void GameMaster::main(sf::RenderWindow& window, sf::Event& event){
	//Creating components of game/map -----------------------------

	//Map
	std::vector<Map> map = Map::stage1(window);
	std::vector<Point> points = Point::stage1();

	//mask for teleport
	std::vector<Map> mask{ Map(window, sf::Vector2f(17 * MAP_PIXELS_SIZE, 9 * MAP_PIXELS_SIZE), sf::Vector2f(2 * MAP_PIXELS_SIZE, MAP_PIXELS_SIZE), sf::Color::Black),
		Map(window, sf::Vector2f(0, 9 * MAP_PIXELS_SIZE), sf::Vector2f(2 * MAP_PIXELS_SIZE, MAP_PIXELS_SIZE), sf::Color::Black) };

	//teleport 
	std::vector<Map> teleport{ Map(window, sf::Vector2f(-1 * MAP_PIXELS_SIZE, 9 * MAP_PIXELS_SIZE), sf::Vector2f(MAP_PIXELS_SIZE, MAP_PIXELS_SIZE), sf::Color::White),
		Map(window, sf::Vector2f(19 * MAP_PIXELS_SIZE, 9 * MAP_PIXELS_SIZE), sf::Vector2f(MAP_PIXELS_SIZE, MAP_PIXELS_SIZE), sf::Color::White) };

	//creating player sprite
	Player pl(window, "./sprites/player.png", sf::Vector2f(MAP_OFFSET_X + 9 * MAP_PIXELS_SIZE, MAP_OFFSET_Y + 14 * MAP_PIXELS_SIZE));

	//creating Enemies
	//TODO

	//initialise game with starting values
	init();

	//loop for framerate-independent gameplay - TODO
	//float delta = 0.0015f;
	//float nextTime = clock.getElapsedTime().asSeconds();

	//mainloop
	while (!exit) {
		window.clear();

		if (!pause) {
			//Player test
			//float currTime = clock.getElapsedTime().asSeconds();
			//if (currTime >= nextTime) {
			//	nextTime += delta;
				window.clear();

				//map drawing
				for (auto& obj : map) {
					obj.draw(window);
					if (pl.doesCollide(obj.getShape()))
						pl.stop();
				}

				//teleport handling
				if (pl.doesCollide(teleport[0].getShape())){
					pl.setPosition(18.f, 9.f);
					pl.setmoveLeft();
				} else if (pl.doesCollide(teleport[1].getShape())) {
					pl.setPosition(0.f, 9.f);
					pl.setmoveRight();
				}

				//points drawing + handling
				for (auto it = points.begin(); it < points.end();) {

					if (pl.doesCollide(it->getShape())) {
						it = points.erase(it);
						updateScore();
					} else {
						it->draw(window);
						++it;
					}
				}

				//player actions + drawing
				//pl.update(window, event, map);
				pl.draw(window);

				// drawing mask for teleport
				mask[0].draw(window);
				mask[1].draw(window);
			//} else{
			//	int sleepTime = (int)(1000.0 * (nextTime - currTime));
			//	if (sleepTime > 0) {
			//		Sleep(sleepTime);
			//	}
			//}


		} else {

			//do something if pause is clicked ( Display PAUSE, Enter to continue, escape to exit game
			std::cout << "Przerwa" << std::endl;

		}


		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::KeyPressed:
				switch (event.key.code) {
				case sf::Keyboard::Escape:
					if (pause == true){
						exit = true;
					}
					else {
						pause = true;
					}
					break;
				}
				break;
			}
		}


		window.display();
	}

}
