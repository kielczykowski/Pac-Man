#pragma once
#include "MenuWindow.h"
class GameObject
{
protected:
	sf::Sprite body;
	sf::Texture bodytexture;


public:
	GameObject(sf::RenderWindow& window, sf::String path,sf::Vector2f& position);
	virtual ~GameObject();
	virtual void update(sf::RenderWindow& window, sf::Event& event) = 0;
	void draw(sf::RenderWindow& window);

};

