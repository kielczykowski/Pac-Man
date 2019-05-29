#pragma once
#include "Definitions.h"
class Map
{
private:
	sf::RectangleShape shape_;
	
public:

	Map(sf::RenderWindow& window, sf::Vector2f& position, sf::Vector2f& size,sf::Color color = sf::Color::Green);
	~Map();

	sf::RectangleShape getShape() const;

	void draw(sf::RenderWindow& window) const;
	static std::vector<Map> stage1(sf::RenderWindow& window);

	
};

