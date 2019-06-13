#include "stdafx.h"
#include "GameLogic.h"


void GameLogic::teleportLogic(std::vector<Map>& teleport, Player& pl,std::vector<Enemy>& enemies){
	if (pl.doesCollide(teleport[0].getShape())){
		pl.setPosition(18.f, 9.f);
		pl.setmoveLeft();
	}
	else if (pl.doesCollide(teleport[1].getShape())) {
		pl.setPosition(0.f, 9.f);
		pl.setmoveRight();
	}

	for (int i = 0; i < enemies.size();i++) {
		if (enemies[i].doesCollide(teleport[0].getShape())){
			enemies[i].setPosition(18.f, 9.f);
			enemies[i].setmoveLeft();
			enemies[i].startClock();
		}
		else if (enemies[i].doesCollide(teleport[1].getShape())) {
			enemies[i].setPosition(0.f, 9.f);
			enemies[i].setmoveRight();
			enemies[i].startClock();
		}
	}

}

int GameLogic::pointsLogic(sf::RenderWindow& window, std::vector<Point>* points, Player* pl, std::vector<Enemy>* enemies){
	for (auto it = points->begin(); it < points->end();) {

		if (pl->doesCollide(it->getShape()) && it->getPower() == SpecialPower::SLOW_EAT_ENEMY) {
			pl->setPower(SpecialPower::SLOW_EAT_ENEMY);
			setValidPower(true);
			startClock();
			for (auto& obj : *enemies){
				obj.changeColor(sf::Color::Red);
			}
			it = points->erase(it);
			return 200;
		}
		else if (pl->doesCollide(it->getShape()) && it->getPower() == SpecialPower::NONE){
			it = points->erase(it);
			return 100;
		}
		else{
			it->draw(window);
			++it;
		}
		
	}
	return 0;
}

void GameLogic::enemyCollision(std::vector<Enemy>& enemies, Player& pl,int& lifes, int& score){
	for (auto& obj : enemies) {
		if (pl.getBody().getGlobalBounds().intersects(obj.getBody().getGlobalBounds()) && pl.getPower() == SpecialPower::NONE) {
			lifes -= 1;
			pl.setPosition(9, 14);
			if (lifes <= 0) {
				setPause(true);
				setExit(true);
			}
		}
		else if (pl.getBody().getGlobalBounds().intersects(obj.getBody().getGlobalBounds()) && pl.getPower() == SpecialPower::SLOW_EAT_ENEMY){
			score += 300;
			obj.setPosition(9, 9);
		}

		if (getElapsedTime() > POWER_VALIDATION_TIME && getValidPower()) {
			pl.setPower(SpecialPower::NONE);
			setValidPower(false);
			for (auto& obj : enemies){
				obj.changeColor(sf::Color::White);
			}
		}
	}
}

void GameLogic::enemyLogic(sf::RenderWindow& window, Player& player, std::vector<Enemy>& enemies, std::vector<Map>& map,const int& xd){
	bool enemyMove = false;
	for (auto& enemy : enemies) {
		if (enemy.getElapsedTime() < AFTER_TELEPORT_TIME) {
			enemy.move();
			enemy.draw(window);
			continue;
		}
		else{
			enemyMove = false;
			sf::Vector2f player_postion = player.getPosition();
			if (player.getPower() == SpecialPower::NONE){
				if (rand() % 2 > 0.5){


					if (rand() % 2 > 0.5) {
						if (player_postion.x < enemy.getPosition().x) {
							if (enemy.checkLeft(map)){
								enemy.setmoveLeft();
								enemyMove = true;
							}
							else {
								enemy.setWantLeft(true);
								enemy.setWantRight(false);
								enemy.setWantDown(false);
								enemy.setWantUp(false);
							}
						}
					}

					if (rand() % 2 > 0.5) {
						if (player_postion.x > enemy.getPosition().x) {
							if (enemy.checkRight(map)){
								enemy.setmoveRight();
								enemyMove = true;
							}
							else {
								enemy.setWantLeft(false);
								enemy.setWantRight(true);
								enemy.setWantDown(false);
								enemy.setWantUp(false);
							}
						}
					}

					if (rand() % 2 > 0.5) {
						if (player_postion.y < enemy.getPosition().y) {
							if (enemy.checkUp(map)){
								enemy.setmoveUp();
								enemyMove = true;
							}
							else {
								enemy.setWantLeft(false);
								enemy.setWantRight(false);
								enemy.setWantDown(false);
								enemy.setWantUp(true);
							}
						}
					}

					if (rand() % 2 > 0.5) {
						if (player_postion.y > enemy.getPosition().y) {
							if (enemy.checkDown(map)){
								enemy.setmoveDown();
								enemyMove = true;
							}
							else {
								enemy.setWantLeft(false);
								enemy.setWantRight(false);
								enemy.setWantDown(true);
								enemy.setWantUp(false);
							}
						}
					}
				}
				else {
					if (xd >= 75){
						switch (rand() % 4){
						case 0:
							if (enemy.checkUp(map)){
								if (rand() % 2 > 0.5) {
									enemy.setmoveUp();
									enemyMove = true;
								}
							}
							break;
						case 1:
							if (enemy.checkDown(map)){
								if (rand() % 2 > 0.5) {
									enemy.setmoveDown();
									enemyMove = true;
								}
							}
							break;
						case 2:
							if (enemy.checkLeft(map)){
								if (rand() % 2 > 0.5) {
									enemy.setmoveLeft();
									enemyMove = true;
								}
							}
							break;
						case 3:
							if (enemy.checkRight(map)){
								if (rand() % 2 > 0.5) {
									enemy.setmoveRight();
									enemyMove = true;
								}
							}
							break;
						}
					}

				}
			}
			else if (player.getPower() == SpecialPower::SLOW_EAT_ENEMY){
				if (rand() % 2 > 0.5) {
					if (player_postion.x < enemy.getPosition().x) {
						if (enemy.checkLeft(map)){
							enemy.setmoveRight();
							enemyMove = true;
						}
						else {
							enemy.setWantLeft(false);
							enemy.setWantRight(true);
							enemy.setWantDown(false);
							enemy.setWantUp(false);
						}
					}
				}

				if (rand() % 2 > 0.5) {
					if (player_postion.x > enemy.getPosition().x) {
						if (enemy.checkRight(map)){
							enemy.setmoveLeft();
							enemyMove = true;
						}
						else {
							enemy.setWantLeft(true);
							enemy.setWantRight(false);
							enemy.setWantDown(false);
							enemy.setWantUp(false);
						}
					}
				}

				if (rand() % 2 > 0.5) {
					if (player_postion.y < enemy.getPosition().y) {
						if (enemy.checkUp(map)){
							enemy.setmoveDown();
							enemyMove = true;
						}
						else {
							enemy.setWantLeft(false);
							enemy.setWantRight(false);
							enemy.setWantDown(true);
							enemy.setWantUp(false);
						}
					}
				}

				if (rand() % 2 > 0.5) {
					if (player_postion.y > enemy.getPosition().y) {
						if (enemy.checkDown(map)){

							enemy.setmoveUp();
							enemyMove = true;
						}
						else {
							enemy.setWantLeft(false);
							enemy.setWantRight(false);
							enemy.setWantDown(false);
							enemy.setWantUp(true);
						}
					}
				}

				if (enemyMove == false) {
					if (xd >= 75){
						if (enemy.checkUp(map)) {
							enemy.setmoveUp();
						}
						else if (enemy.checkLeft(map)) {
							enemy.setmoveLeft();
						}
						else if (enemy.checkDown(map)) {
							enemy.setmoveDown();
						}
						else if (enemy.checkRight(map)) {
							enemy.setmoveRight();
						}
						else{}
					}

				}

			}
			else{}

			if (enemy.checkRight(map) && enemy.getWantRight()) {
				enemy.setmoveRight();
			}
			else if (enemy.checkLeft(map) && enemy.getWantLeft()) {
				enemy.setmoveLeft();
			}
			else if (enemy.checkUp(map) && enemy.getWantUp()) {
				enemy.setmoveUp();
			}
			else if (enemy.checkDown(map) && enemy.getWantDown()) {
				enemy.setmoveDown();
			}
			else {}

			enemy.move();
			enemy.draw(window);
		}
	}
}

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
bool GameLogic::getValidPower() const{
	return valid_power_;
}
void GameLogic::setPause(bool logic){
	pause_ = logic;
}
void GameLogic::setExit(bool logic){
	exit_ = logic;
}
void GameLogic::setValidPower(bool logic){
	valid_power_ = logic;
}

void GameLogic::setSaveScore(bool logic){
	save_score_ = logic;
}
bool GameLogic::getSaveScore() const{
	return save_score_;
}

void GameLogic::startClock(){
	clock_.restart();
}
float GameLogic::getElapsedTime(){
	return clock_.getElapsedTime().asSeconds();
}


GameLogic::GameLogic()
{
	valid_power_ = false;
	pause_ = false;
	exit_ = false;
	save_score_ = false;
}


GameLogic::~GameLogic()
{
}
