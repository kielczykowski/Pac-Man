#include "stdafx.h"
#include "Player.h"


Player::Player(sf::RenderWindow& window, sf::String path, sf::Vector2f& position, float speed) : GameObject(window, path, position)
{
	std::cout << "PLEJER" << std::endl;
	this->speed = speed;
	this->speedx = 0;
	this->speedy = 0;
	wantDownwards = false;
	wantUpwards = false;
	wantRight = false;
	wantLeft = false;
}


Player::~Player()
{
}

void Player::update(sf::RenderWindow& window, sf::Event& event, std::vector<Map>& map){
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::KeyPressed:
			switch (event.key.code) {
			case sf::Keyboard::Up:
				if (checkUp(map)){
					setmoveUp();
					wantUpwards = false;
				}
				else {
					wantUpwards = true;
					wantDownwards = false;
				}
				break;

			case sf::Keyboard::Down:
				if (checkDown(map)) {
					setmoveDown();
					wantDownwards = false;
				}
				else {
					wantDownwards = true;
					wantUpwards = false;
				}
				break;

			case sf::Keyboard::Left:
				if (checkLeft(map)) {
					setmoveLeft();
					wantLeft = false;
				}
				else {
					wantLeft = true;
					wantRight = false;
				}
				break;

			case sf::Keyboard::Right:
				if (checkRight(map)) {
					setmoveRight();
					wantRight = false;
				}
				else {
					wantRight = true;
					wantLeft = false;
				}
				break;
			}
		}

	}
	this->body.move(speedx, speedy);
}

void Player::getStates() {
	std::cout << std::endl;
	std::cout << "stany zmiennych boolean" << std::endl;
	std::cout << "góra: " << wantUpwards << std::endl;
	std::cout << "dó³: " << wantDownwards << std::endl;
	std::cout << "lewo: " << wantLeft << std::endl;
	std::cout << "prawo: " << wantRight << std::endl;
}

void Player::setmoveDown() {
	speedx = 0;
	speedy = speed;
}
void Player::setmoveUp() {
	speedx = 0;
	speedy = -speed;
}

void Player::setmoveLeft() {
	speedx =-speed;
	speedy = 0;
}

void Player::setmoveRight() {
	speedx = speed;
	speedy = 0;
}

void Player::stop() {
	body.move(-speedx, -speedy);
	speedx = 0;
	speedy = 0;
}

bool Player::checkRight(std::vector<Map>& objects) {
	body.move(speed, 0);
	for (auto& object : objects) {
		if (body.getGlobalBounds().intersects(object.getShape().getGlobalBounds())){
			body.move(-speed, 0);
			return false;
		}
	}
	body.move(-speed, 0);
	return true;
}
bool Player::checkLeft(std::vector<Map>& objects) {
	body.move(-speed, 0);
	for (auto& object : objects) {
		if (body.getGlobalBounds().intersects(object.getShape().getGlobalBounds())){
			body.move(speed, 0);
			return false;
		}
	}
	body.move(speed, 0);
	return true;
}

bool Player::checkUp(std::vector<Map>& objects) {
	body.move(0,-speed);
	for (auto& object : objects) {
		if (body.getGlobalBounds().intersects(object.getShape().getGlobalBounds())){
			body.move(0, speed);
			return false;
		}
	}
	body.move(0, speed);
	return true;
}

bool Player::checkDown(std::vector<Map>& objects) {
	body.move(0, speed);
	for (auto& object : objects) {
		if (body.getGlobalBounds().intersects(object.getShape().getGlobalBounds())){
			body.move(0,-speed);
			return false;
		}
	}
	body.move(0, -speed);
	return true;
}

bool Player::doesCollide(sf::RectangleShape& shape){
	return body.getGlobalBounds().intersects(shape.getGlobalBounds());
}

void Player::checkMovementPossibility(sf::RectangleShape& shape){
	sf::FloatRect boundries = body.getGlobalBounds();
	//boundries.
	//

}

