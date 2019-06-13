#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy(sf::RenderWindow& window, sf::String path, sf::Vector2f& position, float speed) : Player(window, path, position, speed)
{
	std::cout << "enemy" << std::endl;
}


Enemy::~Enemy()
{
}

//void Player::update(sf::RenderWindow& window, sf::Event& event, std::vector<Map>& map){
//	std::cout << "XD" << std::endl;
//}

void Enemy::changeColor(const sf::Color& color){
		body_.setColor(color);
}

void Enemy::startClock(){
	clock_.restart();
}
float Enemy::getElapsedTime(){
	return clock_.getElapsedTime().asSeconds();
}
