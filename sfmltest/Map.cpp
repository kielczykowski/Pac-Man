#include "stdafx.h"
#include "Map.h"


Map::Map(sf::RenderWindow& window, sf::Vector2f& position, sf::Vector2f& size, sf::Color color)
{
	position.x = position.x * MAP_PIXELS_SIZE + MAP_OFFSET_X;
	position.y = position.y * MAP_PIXELS_SIZE + MAP_OFFSET_Y;
	size.x = size.x * MAP_PIXELS_SIZE;
	size.y = size.y * MAP_PIXELS_SIZE;
	shape_.setPosition(position);
	shape_.setSize(size);
	shape_.setFillColor(color);

}


Map::~Map()
{
}

void Map::draw(sf::RenderWindow& window) {
	window.draw(shape_);
}

std::vector<Map> Map::stage1(sf::RenderWindow& window) {
	std::vector<Map> objects;
	objects.push_back(Map(window, sf::Vector2f(0, 0), sf::Vector2f(19, 2)));
	objects.push_back(Map(window, sf::Vector2f(0, 2), sf::Vector2f(2, 7)));
	objects.push_back(Map(window, sf::Vector2f(17, 2), sf::Vector2f(2, 7)));
	objects.push_back(Map(window, sf::Vector2f(6, 2), sf::Vector2f(1, 3)));
	objects.push_back(Map(window, sf::Vector2f(12, 2), sf::Vector2f(1, 3)));
	objects.push_back(Map(window, sf::Vector2f(3, 4), sf::Vector2f(1, 1)));
	objects.push_back(Map(window, sf::Vector2f(4, 4), sf::Vector2f(1, 1)));
	objects.push_back(Map(window, sf::Vector2f(4, 3), sf::Vector2f(1, 1)));
	objects.push_back(Map(window, sf::Vector2f(8, 3), sf::Vector2f(3, 1)));
	objects.push_back(Map(window, sf::Vector2f(14, 4), sf::Vector2f(2, 1)));
	objects.push_back(Map(window, sf::Vector2f(14, 3), sf::Vector2f(1, 1)));
	objects.push_back(Map(window, sf::Vector2f(15, 6), sf::Vector2f(1, 7)));
	objects.push_back(Map(window, sf::Vector2f(3, 6), sf::Vector2f(1, 7)));
	objects.push_back(Map(window, sf::Vector2f(5, 6), sf::Vector2f(9, 1)));
	objects.push_back(Map(window, sf::Vector2f(5, 7), sf::Vector2f(1, 2)));
	objects.push_back(Map(window, sf::Vector2f(13, 7), sf::Vector2f(1, 2)));
	objects.push_back(Map(window, sf::Vector2f(13, 10), sf::Vector2f(1, 2)));
	objects.push_back(Map(window, sf::Vector2f(5, 10), sf::Vector2f(1, 2)));
	objects.push_back(Map(window, sf::Vector2f(5, 12), sf::Vector2f(4, 1)));
	objects.push_back(Map(window, sf::Vector2f(10, 12), sf::Vector2f(4, 1)));
	//Mobs Spawn
	objects.push_back(Map(window, sf::Vector2f(8, 8), sf::Vector2f(1, 1)));
	objects.push_back(Map(window, sf::Vector2f(10, 8), sf::Vector2f(1, 1)));
	objects.push_back(Map(window, sf::Vector2f(7, 8), sf::Vector2f(1, 2)));
	objects.push_back(Map(window, sf::Vector2f(7, 10), sf::Vector2f(5, 1)));
	objects.push_back(Map(window, sf::Vector2f(11, 8), sf::Vector2f(1, 2)));

	objects.push_back(Map(window, sf::Vector2f(0, 10), sf::Vector2f(2, 7)));
	objects.push_back(Map(window, sf::Vector2f(17, 10), sf::Vector2f(2, 7)));
	objects.push_back(Map(window, sf::Vector2f(0, 17), sf::Vector2f(19, 2)));
	objects.push_back(Map(window, sf::Vector2f(3, 14), sf::Vector2f(2, 1)));
	objects.push_back(Map(window, sf::Vector2f(4, 15), sf::Vector2f(1, 1)));
	objects.push_back(Map(window, sf::Vector2f(14, 14), sf::Vector2f(2, 1)));
	objects.push_back(Map(window, sf::Vector2f(14, 15), sf::Vector2f(1, 1)));
	objects.push_back(Map(window, sf::Vector2f(6, 14), sf::Vector2f(3, 3)));
	objects.push_back(Map(window, sf::Vector2f(10, 14), sf::Vector2f(3, 3)));
	objects.push_back(Map(window, sf::Vector2f(9, 15), sf::Vector2f(1, 2)));



	return objects;
}

sf::RectangleShape Map::getShape(){
	return this->shape_;
}
