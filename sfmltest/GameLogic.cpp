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
				if (pause_ == true){
					exit_ = true;
				}
				else {
					pause_ = true;
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

void GameLogic::pausedGameLogic(sf::RenderWindow& window, sf::Event& event){
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::KeyPressed:
			switch (event.key.code) {
			case sf::Keyboard::Enter:
				setPause(false);
				break;
			case sf::Keyboard::Escape:
				setExit(true);
				break;
			}
		}
	}
}

void GameLogic::afterGameLogic(sf::RenderWindow& window, sf::Event& event, sf::String& nick){
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::TextEntered:
			nick += event.text.unicode;
			break;
		case sf::Event::KeyPressed:
			switch (event.key.code) {
			case sf::Keyboard::Enter:
				save_score_ = true;
				break;
			case sf::Keyboard::BackSpace:
				nick = nick.substring(0, nick.getSize() - 1);
				break;
			}
			break;
		}
	}
}

bool GameLogic::getPause() const{
	return pause_;
}
bool GameLogic::getExit() const{
	return exit_;
}
void GameLogic::setPause(bool logic){
	pause_ = logic;
}
void GameLogic::setExit(bool logic){
	exit_ = logic;
}

void GameLogic::setSaveScore(bool logic){
	save_score_ = logic;
}
bool GameLogic::getSaveScore() const{
	return save_score_;
}


GameLogic::GameLogic()
{
	pause_ = false;
	exit_ = false;
	save_score_ = false;
}


GameLogic::~GameLogic()
{
}