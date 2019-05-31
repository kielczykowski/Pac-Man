#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy(sf::RenderWindow& window, sf::String path, sf::Vector2f& position, float speed) : GameObject(window, path, position, speed)
{
	std::cout << "enemy" << std::endl;
}


Enemy::~Enemy()
{
}

//void Player::update(sf::RenderWindow& window, sf::Event& event, std::vector<Map>& map){
//	std::cout << "XD" << std::endl;
//}

void Enemy::changeColor(){
	if (body_.getColor() == sf::Color::White){
		body_.setColor(sf::Color::Red);
	}
	else{
		body_.setColor(sf::Color::White);
	}
}
