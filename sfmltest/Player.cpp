#include "stdafx.h"
#include "Player.h"


Player::Player(sf::RenderWindow& window, sf::String path, sf::Vector2f& position, float speed) : GameObject(window, path, position)
{
	std::cout << "PLEJER" << std::endl;
	this->speed = speed;
	this->speedx = 0;
	this->speedy = 0;
}


Player::~Player()
{
}

void Player::update(sf::RenderWindow& window, sf::Event& event){
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::KeyPressed:
			switch (event.key.code) {
			case sf::Keyboard::Up:
				moveUp();
				break;

			case sf::Keyboard::Down:
				moveDown();
				break;

			case sf::Keyboard::Left:
				moveLeft();
				break;

			case sf::Keyboard::Right:
				moveRight();
				break;
			}
		}

	}
	this->body.move(speedx, speedy);
}

void Player::moveDown() {
	speedx = 0;
	speedy = speed;
}
void Player::moveUp() {
	speedx = 0;
	speedy = -speed;
}

void Player::moveLeft() {
	speedx =-speed;
	speedy = 0;
}

void Player::moveRight() {
	speedx = speed;
	speedy = 0;
}

