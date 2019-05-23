#include "stdafx.h"
#include "GameLogic.h"

void GameLogic::playerLogic(sf::RenderWindow& window, Player& player, sf::Event& event, std::vector<Map>& map){
	bool canUp = player.checkUp(map);
	bool canDown = player.checkDown(map);
	bool canLeft = player.checkLeft(map);
	bool canRight = player.checkRight(map);
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::KeyPressed:
			switch (event.key.code) {
			case sf::Keyboard::Up:
				if (canUp){
					player.setmoveUp();
					player.setWantUp(false);
					player.setWantDown(false);
					player.setWantRight(false);
					player.setWantLeft(false);
					std::cout << "UP" << std::endl;
				}
				else {
					player.setWantUp(true);
					player.setWantDown(false);
					player.setWantRight(false);
					player.setWantLeft(false);
					std::cout << "UP" << std::endl;
				}
				break;

			case sf::Keyboard::Down:
				if (canDown) {
					player.setmoveDown();
					player.setWantUp(false);
					player.setWantDown(false);
					player.setWantRight(false);
					player.setWantLeft(false);
					std::cout << "Down" << std::endl;
				}
				else {
					player.setWantUp(false);
					player.setWantDown(true);
					player.setWantRight(false);
					player.setWantLeft(false);
					std::cout << "Down" << std::endl;
				}
				break;

			case sf::Keyboard::Left:
				if (canLeft) {
					player.setmoveLeft();
					player.setWantUp(false);
					player.setWantDown(false);
					player.setWantRight(false);
					player.setWantLeft(false);
				}
				else {
					player.setWantUp(false);
					player.setWantDown(false);
					player.setWantRight(false);
					player.setWantLeft(true);
				}
				break;

			case sf::Keyboard::Right:
				if (canRight) {
					player.setmoveRight();
					player.setWantUp(false);
					player.setWantDown(false);
					player.setWantRight(false);
					player.setWantLeft(false);
				}
				else {
					player.setWantUp(false);
					player.setWantDown(false);
					player.setWantRight(true);
					player.setWantLeft(false);
				}
				break;
			case sf::Keyboard::Escape:
				if (pause == true){
					exit = true;
				}
				else {
					pause = true;
				}
				break;
				//case sf::Keyboard::Escape:
				//	window.close();
				//	break;
			}
		}

	}

	//moving
	if (canUp && player.getWantUp()) {
		player.setmoveUp();
		player.setWantUp(false);
	}
	else if (canDown && player.getWantDown()) {
		player.setmoveDown();
		player.setWantDown(false);
	}
	else if (canLeft && player.getWantLeft()) {
		player.setmoveLeft();
		player.setWantLeft(false);
	}
	else if (canRight && player.getWantRight()) {
		player.setmoveRight();
		player.setWantRight(false);
	}
	else {}

	//player.getStates();

	//player.getBody().move(player.getXSpeed(), player.getYSpeed());
	player.move();
}

bool GameLogic::getPause(){
	return pause;
}
bool GameLogic::getExit(){
	return exit;
}
void GameLogic::setPause(bool logic){
	pause = logic;
}
void GameLogic::setExit(bool logic){
	exit = logic;
}


GameLogic::GameLogic()
{
	pause = false;
	exit = false;
}


GameLogic::~GameLogic()
{
}
