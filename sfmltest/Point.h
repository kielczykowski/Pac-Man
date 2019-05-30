#pragma once
#include "Enemy.h"
class Point
{
protected:
	sf::CircleShape	shape_;
	SpecialPower	power_;
	//sf::Sprite body;
	//sf::Texture bodytexture;

public:
	Point(sf::Vector2f& position, const SpecialPower& pow = SpecialPower::NONE, const sf::Color& color= sf::Color::Red);
	static std::vector<Point> stage1();

	void draw(sf::RenderWindow& window) const;
	sf::CircleShape getShape() const;

	SpecialPower getPower() const;
};

//virtual ~Point();
//virtual void update(Player& player);

