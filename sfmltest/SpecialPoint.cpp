#include "stdafx.h"
#include "SpecialPoint.h"


SpecialPoint::SpecialPoint(sf::Vector2f & position, const sf::Color& color, sf::String path): Point(position,color) {
	//assert(texture.loadFromFile(path));
	//shape.setTexture(&texture);
	//std::cout << "wesz³em" <<std::endl;
	power = SpecialPower::SLOW_EAT_ENEMY;
}

std::vector<Point> SpecialPoint::stage1(){
	std::vector<Point> objects = Point::stage1();
	objects.push_back(SpecialPoint(sf::Vector2f(3 * MAP_PIXELS_SIZE, 3 * MAP_PIXELS_SIZE)));
	objects.push_back(SpecialPoint(sf::Vector2f(15 * MAP_PIXELS_SIZE, 3 * MAP_PIXELS_SIZE)));
	objects.push_back(SpecialPoint(sf::Vector2f(15 * MAP_PIXELS_SIZE, 15 * MAP_PIXELS_SIZE)));
	objects.push_back(SpecialPoint(sf::Vector2f(3 * MAP_PIXELS_SIZE, 15 * MAP_PIXELS_SIZE)));


	return objects;
}

SpecialPower SpecialPoint::getPower() {
	return power;
}
//SpecialPoint::SpecialPoint()
//{
//}
//
//
//SpecialPoint::~SpecialPoint()
//{
//}
