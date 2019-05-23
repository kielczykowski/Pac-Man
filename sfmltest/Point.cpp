#include "stdafx.h"
#include "Point.h"


Point::Point(sf::Vector2f& position, const sf::Color& color)
{
	position.x = position.x + MAP_OFFSET_X + 0.25f * MAP_PIXELS_SIZE;
	position.y = position.y + MAP_OFFSET_Y + 0.25f * MAP_PIXELS_SIZE;
	shape.setRadius(0.25f * MAP_PIXELS_SIZE);
	shape.setPosition(position);
	shape.setFillColor(color);
}

std::vector<Point> Point::stage1() {
	std::vector<Point> objects;
	for (int i = 2; i < 17; i++){
		objects.push_back(Point(sf::Vector2f(2 * MAP_PIXELS_SIZE, i * MAP_PIXELS_SIZE)));
		objects.push_back(Point(sf::Vector2f(16 * MAP_PIXELS_SIZE, i * MAP_PIXELS_SIZE)));
	}
	for (int i = 3; i < 16; i++){
		objects.push_back(Point(sf::Vector2f(i * MAP_PIXELS_SIZE, 5 * MAP_PIXELS_SIZE)));
		objects.push_back(Point(sf::Vector2f(i * MAP_PIXELS_SIZE, 13 * MAP_PIXELS_SIZE)));
	}
	for (int i = 0; i < 3; i++) {
		objects.push_back(Point(sf::Vector2f((i+3) * MAP_PIXELS_SIZE, 2 * MAP_PIXELS_SIZE)));
		objects.push_back(Point(sf::Vector2f((i + 3) * MAP_PIXELS_SIZE, 16 * MAP_PIXELS_SIZE)));
		objects.push_back(Point(sf::Vector2f((i + 13) * MAP_PIXELS_SIZE, 2 * MAP_PIXELS_SIZE)));
		objects.push_back(Point(sf::Vector2f((i + 13) * MAP_PIXELS_SIZE, 16 * MAP_PIXELS_SIZE)));

		objects.push_back(Point(sf::Vector2f((i + 8) * MAP_PIXELS_SIZE, 2 * MAP_PIXELS_SIZE)));
		objects.push_back(Point(sf::Vector2f((i + 8) * MAP_PIXELS_SIZE, 4 * MAP_PIXELS_SIZE)));
		objects.push_back(Point(sf::Vector2f((i + 8) * MAP_PIXELS_SIZE, 9 * MAP_PIXELS_SIZE)));
		objects.push_back(Point(sf::Vector2f(7 * MAP_PIXELS_SIZE, (2+i) * MAP_PIXELS_SIZE)));
		objects.push_back(Point(sf::Vector2f(11 * MAP_PIXELS_SIZE, (2 + i) * MAP_PIXELS_SIZE)));
		objects.push_back(Point(sf::Vector2f( 6 * MAP_PIXELS_SIZE, (8+i) * MAP_PIXELS_SIZE)));
		objects.push_back(Point(sf::Vector2f( 12 * MAP_PIXELS_SIZE, (8 + i) * MAP_PIXELS_SIZE)));
	}

	for (int i = 0; i < 7; i++) {
		objects.push_back(Point(sf::Vector2f(4 * MAP_PIXELS_SIZE,(i+6) * MAP_PIXELS_SIZE)));
		objects.push_back(Point(sf::Vector2f(14 * MAP_PIXELS_SIZE, (i + 6) * MAP_PIXELS_SIZE)));
		objects.push_back(Point(sf::Vector2f((i+6) * MAP_PIXELS_SIZE, 7 * MAP_PIXELS_SIZE)));
		objects.push_back(Point(sf::Vector2f((i + 6) * MAP_PIXELS_SIZE, 11 * MAP_PIXELS_SIZE)));
		//objects.push_back(Point(sf::Vector2f( 6 * MAP_PIXELS_SIZE, (8+i) * MAP_PIXELS_SIZE)));
		//objects.push_back(Point(sf::Vector2f( 12 * MAP_PIXELS_SIZE, (8 + i) * MAP_PIXELS_SIZE)));
	}
	for(int i = 0; i < 2; i++) {
		objects.push_back(Point(sf::Vector2f(5 * MAP_PIXELS_SIZE, (3+i) * MAP_PIXELS_SIZE)));
		objects.push_back(Point(sf::Vector2f(13 * MAP_PIXELS_SIZE, (3 + i) * MAP_PIXELS_SIZE)));
		objects.push_back(Point(sf::Vector2f(5 * MAP_PIXELS_SIZE, (14 + i) * MAP_PIXELS_SIZE)));
		objects.push_back(Point(sf::Vector2f(13 * MAP_PIXELS_SIZE, (14 + i) * MAP_PIXELS_SIZE)));
	}

	objects.push_back(Point(sf::Vector2f(5 * MAP_PIXELS_SIZE, 9 * MAP_PIXELS_SIZE)));
	objects.push_back(Point(sf::Vector2f(9 * MAP_PIXELS_SIZE, 8 * MAP_PIXELS_SIZE)));
	objects.push_back(Point(sf::Vector2f(13 * MAP_PIXELS_SIZE, 9 * MAP_PIXELS_SIZE)));
	objects.push_back(Point(sf::Vector2f(9 * MAP_PIXELS_SIZE, 12 * MAP_PIXELS_SIZE)));
	

	return objects;
}

void Point::draw(sf::RenderWindow& window) {
	window.draw(shape);
}

sf::CircleShape Point::getShape() {
	return this->shape;
}
//
//
//Point::~Point()
//{
//}
