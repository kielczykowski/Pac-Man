#pragma once
#include "Player.h"
class Enemy : public GameObject
{
public:
	Enemy(sf::RenderWindow& window, sf::String path, sf::Vector2f& position, float speed = 0.8f);
	~Enemy();
	void changeColor();
	
	//void update(sf::RenderWindow& window, sf::Event& event, std::vector<Map>& map) override;
};

