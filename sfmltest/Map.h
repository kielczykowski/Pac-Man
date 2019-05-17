#pragma once
#include "MenuWindow.h"
class Map
{
private:
	sf::RectangleShape shape;
	
public:
	Map(sf::RenderWindow& window, sf::Vector2f& position, sf::Vector2f& size,sf::Color color = sf::Color::Green);
	~Map();
	void draw(sf::RenderWindow& window);
	static std::vector<Map> stage1(sf::RenderWindow& window);

	sf::RectangleShape getShape();
};

