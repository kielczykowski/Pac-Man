#include "stdafx.h"
#include "Map.h"


Map::Map(sf::RenderWindow& window, sf::Vector2f& position, sf::Vector2f& size, sf::Color color)
{
	position.x = position.x + MAP_OFFSET_X;
	position.y = position.y + MAP_OFFSET_Y;
	shape.setPosition(position);
	shape.setSize(size);
	shape.setFillColor(color);
	
}


Map::~Map()
{
}

void Map::draw(sf::RenderWindow& window) {
	window.draw(shape);
}

std::vector<Map> Map::stage1(sf::RenderWindow& window) {
	std::vector<Map> objects;
	objects.push_back(Map(window, sf::Vector2f(0, 0), sf::Vector2f(MAP_PIXELS_SIZE * 19, MAP_PIXELS_SIZE * 2)));
	objects.push_back(Map(window, sf::Vector2f(0, 2*MAP_PIXELS_SIZE), sf::Vector2f(MAP_PIXELS_SIZE * 2, MAP_PIXELS_SIZE * 7)));
	objects.push_back(Map(window, sf::Vector2f(17*MAP_PIXELS_SIZE, 2 * MAP_PIXELS_SIZE), sf::Vector2f(MAP_PIXELS_SIZE * 2, MAP_PIXELS_SIZE * 7)));
	objects.push_back(Map(window, sf::Vector2f(6 * MAP_PIXELS_SIZE, 2 * MAP_PIXELS_SIZE), sf::Vector2f(MAP_PIXELS_SIZE, MAP_PIXELS_SIZE * 3)));
	objects.push_back(Map(window, sf::Vector2f(12 * MAP_PIXELS_SIZE, 2 * MAP_PIXELS_SIZE), sf::Vector2f(MAP_PIXELS_SIZE, MAP_PIXELS_SIZE * 3)));
	objects.push_back(Map(window, sf::Vector2f(3 * MAP_PIXELS_SIZE, 4 * MAP_PIXELS_SIZE), sf::Vector2f(MAP_PIXELS_SIZE, MAP_PIXELS_SIZE)));
	objects.push_back(Map(window, sf::Vector2f(4 * MAP_PIXELS_SIZE, 4 * MAP_PIXELS_SIZE), sf::Vector2f(MAP_PIXELS_SIZE, MAP_PIXELS_SIZE)));
	objects.push_back(Map(window, sf::Vector2f(4 * MAP_PIXELS_SIZE, 3 * MAP_PIXELS_SIZE), sf::Vector2f(MAP_PIXELS_SIZE, MAP_PIXELS_SIZE)));
	objects.push_back(Map(window, sf::Vector2f(8 * MAP_PIXELS_SIZE, 3 * MAP_PIXELS_SIZE), sf::Vector2f(3 * MAP_PIXELS_SIZE, MAP_PIXELS_SIZE)));
	objects.push_back(Map(window, sf::Vector2f(14 * MAP_PIXELS_SIZE, 4 * MAP_PIXELS_SIZE), sf::Vector2f(2 * MAP_PIXELS_SIZE, MAP_PIXELS_SIZE)));
	objects.push_back(Map(window, sf::Vector2f(14 * MAP_PIXELS_SIZE, 3 * MAP_PIXELS_SIZE), sf::Vector2f( MAP_PIXELS_SIZE, MAP_PIXELS_SIZE)));
	objects.push_back(Map(window, sf::Vector2f(15 * MAP_PIXELS_SIZE, 6 * MAP_PIXELS_SIZE), sf::Vector2f(MAP_PIXELS_SIZE, 7 * MAP_PIXELS_SIZE)));
	objects.push_back(Map(window, sf::Vector2f(3 * MAP_PIXELS_SIZE, 6 * MAP_PIXELS_SIZE), sf::Vector2f(MAP_PIXELS_SIZE, 7 * MAP_PIXELS_SIZE)));
	objects.push_back(Map(window, sf::Vector2f(5 * MAP_PIXELS_SIZE, 6 * MAP_PIXELS_SIZE), sf::Vector2f(9 * MAP_PIXELS_SIZE, MAP_PIXELS_SIZE)));
	objects.push_back(Map(window, sf::Vector2f(5 * MAP_PIXELS_SIZE, 7 * MAP_PIXELS_SIZE), sf::Vector2f(MAP_PIXELS_SIZE, 2 *MAP_PIXELS_SIZE)));
	objects.push_back(Map(window, sf::Vector2f(13 * MAP_PIXELS_SIZE, 7 * MAP_PIXELS_SIZE), sf::Vector2f(MAP_PIXELS_SIZE, 2 * MAP_PIXELS_SIZE)));
	objects.push_back(Map(window, sf::Vector2f(13 * MAP_PIXELS_SIZE, 10 * MAP_PIXELS_SIZE), sf::Vector2f(MAP_PIXELS_SIZE, 2 * MAP_PIXELS_SIZE)));
	objects.push_back(Map(window, sf::Vector2f(5 * MAP_PIXELS_SIZE, 10 * MAP_PIXELS_SIZE), sf::Vector2f(MAP_PIXELS_SIZE, 2 * MAP_PIXELS_SIZE)));
	objects.push_back(Map(window, sf::Vector2f(5 * MAP_PIXELS_SIZE, 12 * MAP_PIXELS_SIZE), sf::Vector2f(4 * MAP_PIXELS_SIZE, MAP_PIXELS_SIZE)));
	objects.push_back(Map(window, sf::Vector2f(10 * MAP_PIXELS_SIZE, 12 * MAP_PIXELS_SIZE), sf::Vector2f(4 * MAP_PIXELS_SIZE, MAP_PIXELS_SIZE)));
	//Mobs Spawn
	objects.push_back(Map(window, sf::Vector2f(8 * MAP_PIXELS_SIZE, 8 * MAP_PIXELS_SIZE), sf::Vector2f(MAP_PIXELS_SIZE, MAP_PIXELS_SIZE)));
	objects.push_back(Map(window, sf::Vector2f(10 * MAP_PIXELS_SIZE, 8 * MAP_PIXELS_SIZE), sf::Vector2f(MAP_PIXELS_SIZE, MAP_PIXELS_SIZE)));
	objects.push_back(Map(window, sf::Vector2f(7 * MAP_PIXELS_SIZE, 8 * MAP_PIXELS_SIZE), sf::Vector2f(MAP_PIXELS_SIZE, 2 * MAP_PIXELS_SIZE)));
	objects.push_back(Map(window, sf::Vector2f(7 * MAP_PIXELS_SIZE, 10 * MAP_PIXELS_SIZE), sf::Vector2f(5 * MAP_PIXELS_SIZE, MAP_PIXELS_SIZE)));
	objects.push_back(Map(window, sf::Vector2f(11 * MAP_PIXELS_SIZE, 8 * MAP_PIXELS_SIZE), sf::Vector2f(MAP_PIXELS_SIZE, 2 * MAP_PIXELS_SIZE)));

	objects.push_back(Map(window, sf::Vector2f(0, 10 * MAP_PIXELS_SIZE), sf::Vector2f(2 * MAP_PIXELS_SIZE, 7 * MAP_PIXELS_SIZE)));
	objects.push_back(Map(window, sf::Vector2f(17 * MAP_PIXELS_SIZE, 10 * MAP_PIXELS_SIZE), sf::Vector2f(2 * MAP_PIXELS_SIZE, 7 * MAP_PIXELS_SIZE)));
	objects.push_back(Map(window, sf::Vector2f(0, 17 * MAP_PIXELS_SIZE), sf::Vector2f(19 *  MAP_PIXELS_SIZE, 2 * MAP_PIXELS_SIZE)));
	objects.push_back(Map(window, sf::Vector2f(3 * MAP_PIXELS_SIZE, 14 * MAP_PIXELS_SIZE), sf::Vector2f(2 * MAP_PIXELS_SIZE, MAP_PIXELS_SIZE)));
	objects.push_back(Map(window, sf::Vector2f(4 * MAP_PIXELS_SIZE, 15 * MAP_PIXELS_SIZE), sf::Vector2f( MAP_PIXELS_SIZE, MAP_PIXELS_SIZE)));
	objects.push_back(Map(window, sf::Vector2f(14 * MAP_PIXELS_SIZE, 14 * MAP_PIXELS_SIZE), sf::Vector2f(2 * MAP_PIXELS_SIZE, MAP_PIXELS_SIZE)));
	objects.push_back(Map(window, sf::Vector2f(14 * MAP_PIXELS_SIZE, 15 * MAP_PIXELS_SIZE), sf::Vector2f( MAP_PIXELS_SIZE, MAP_PIXELS_SIZE)));
	objects.push_back(Map(window, sf::Vector2f(6 * MAP_PIXELS_SIZE, 14 * MAP_PIXELS_SIZE), sf::Vector2f(3 * MAP_PIXELS_SIZE, 3 * MAP_PIXELS_SIZE)));
	objects.push_back(Map(window, sf::Vector2f(10 * MAP_PIXELS_SIZE, 14 * MAP_PIXELS_SIZE), sf::Vector2f(3 * MAP_PIXELS_SIZE, 3 * MAP_PIXELS_SIZE)));
	objects.push_back(Map(window, sf::Vector2f(9 * MAP_PIXELS_SIZE, 15 * MAP_PIXELS_SIZE), sf::Vector2f( MAP_PIXELS_SIZE, 2 * MAP_PIXELS_SIZE)));

	

	return objects;
}

sf::RectangleShape Map::getShape(){
	return this->shape;
}
