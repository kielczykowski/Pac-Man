#include "stdafx.h"
#include "Point.h"


Point::Point(sf::Vector2f& position, const SpecialPower& pow, const sf::Color& color)
{
	position.x = position.x * MAP_PIXELS_SIZE + MAP_OFFSET_X + 0.25f * MAP_PIXELS_SIZE;
	position.y = position.y * MAP_PIXELS_SIZE + MAP_OFFSET_Y + 0.25f * MAP_PIXELS_SIZE;
	shape_.setRadius(0.25f * MAP_PIXELS_SIZE);
	shape_.setPosition(position);
	shape_.setFillColor(color);
	power_ = pow;
}

std::vector<Point> Point::stage1() {
	std::vector<Point> objects;
	for (int i = 2; i < 17; i++){
		objects.push_back(Point(sf::Vector2f(2, i)));
		objects.push_back(Point(sf::Vector2f(16, i)));
	}
	for (int i = 3; i < 16; i++){
		objects.push_back(Point(sf::Vector2f(i, 5)));
		objects.push_back(Point(sf::Vector2f(i, 13)));
	}
	for (int i = 0; i < 3; i++) {
		objects.push_back(Point(sf::Vector2f((i + 3), 2)));
		objects.push_back(Point(sf::Vector2f((i + 3), 16)));
		objects.push_back(Point(sf::Vector2f((i + 13), 2)));
		objects.push_back(Point(sf::Vector2f((i + 13), 16)));

		objects.push_back(Point(sf::Vector2f((i + 8), 2)));
		objects.push_back(Point(sf::Vector2f((i + 8), 4)));
		objects.push_back(Point(sf::Vector2f((i + 8), 9)));
		objects.push_back(Point(sf::Vector2f(7, (2 + i))));
		objects.push_back(Point(sf::Vector2f(11, (2 + i))));
		objects.push_back(Point(sf::Vector2f(6, (8 + i))));
		objects.push_back(Point(sf::Vector2f(12, (8 + i))));
	}

	for (int i = 0; i < 7; i++) {
		objects.push_back(Point(sf::Vector2f(4, (i + 6))));
		objects.push_back(Point(sf::Vector2f(14, (i + 6))));
		objects.push_back(Point(sf::Vector2f((i + 6), 7)));
		objects.push_back(Point(sf::Vector2f((i + 6), 11)));
		//objects.push_back(Point(sf::Vector2f( 6 * MAP_PIXELS_SIZE, (8+i) * MAP_PIXELS_SIZE)));
		//objects.push_back(Point(sf::Vector2f( 12 * MAP_PIXELS_SIZE, (8 + i) * MAP_PIXELS_SIZE)));
	}
	for (int i = 0; i < 2; i++) {
		objects.push_back(Point(sf::Vector2f(5, (3 + i))));
		objects.push_back(Point(sf::Vector2f(13, (3 + i))));
		objects.push_back(Point(sf::Vector2f(5, (14 + i))));
		objects.push_back(Point(sf::Vector2f(13, (14 + i))));
	}

	objects.push_back(Point(sf::Vector2f(5, 9)));
	objects.push_back(Point(sf::Vector2f(9, 8)));
	objects.push_back(Point(sf::Vector2f(13, 9)));
	objects.push_back(Point(sf::Vector2f(9, 12)));

	objects.push_back(Point(sf::Vector2f(3, 3), SpecialPower::SLOW_EAT_ENEMY, sf::Color::Blue));
	objects.push_back(Point(sf::Vector2f(15, 3), SpecialPower::SLOW_EAT_ENEMY, sf::Color::Blue));
	objects.push_back(Point(sf::Vector2f(15, 15), SpecialPower::SLOW_EAT_ENEMY, sf::Color::Blue));
	objects.push_back(Point(sf::Vector2f(3, 15), SpecialPower::SLOW_EAT_ENEMY, sf::Color::Blue));


	return objects;
}

void Point::draw(sf::RenderWindow& window) const{
	window.draw(shape_);
}

sf::CircleShape Point::getShape() const{
	return this->shape_;
}

SpecialPower Point::getPower() const{
	return power_;
}
//
//
//Point::~Point()
//{
//}
