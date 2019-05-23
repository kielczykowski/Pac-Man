#pragma once
#include "Player.h"
class Point
{
protected:
	sf::CircleShape shape;
	SpecialPower power;
	//sf::Sprite body;
	//sf::Texture bodytexture;

public:
	Point(sf::Vector2f& position, const SpecialPower& pow = SpecialPower::NONE, const sf::Color& color= sf::Color::Red);
	static std::vector<Point> stage1();
	//virtual ~Point();
	//virtual void update(Player& player);
	void draw(sf::RenderWindow& window);
	sf::CircleShape getShape();

	SpecialPower getPower();
};

