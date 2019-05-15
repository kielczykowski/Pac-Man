#pragma once
#include "GameObject.h"
 
class Player : public GameObject
{
private: 
	float speed;
	float speedx;
	float speedy;

public:
	Player(sf::RenderWindow& window, sf::String path, sf::Vector2f& position, float speed = 1.f);
	~Player();
	void update(sf::RenderWindow& window, sf::Event& event) override;

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

};

