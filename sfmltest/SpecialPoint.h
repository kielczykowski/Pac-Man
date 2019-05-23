#pragma once
#include "Point.h"
class SpecialPoint : public Point {
private:
	//sf::Texture texture;
	SpecialPower power;

public:
	SpecialPoint(sf::Vector2f& position, const sf::Color& color = sf::Color::Blue, sf::String path = "./sprites/special.jpg");
	static std::vector<Point> stage1();
	SpecialPower getPower();
	//~SpecialPoint();
};

