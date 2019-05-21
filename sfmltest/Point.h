#pragma once
#include "Player.h"
class Point
{
private:
	sf::CircleShape shape;
	//sf::Sprite body;
	//sf::Texture bodytexture;

public:
	Point(sf::Vector2f& position, const sf::Color& color= sf::Color::Red);
	static std::vector<Point> stage1();
	//virtual ~Point();
	//virtual void update(Player& player);
	void draw(sf::RenderWindow& window);
};

