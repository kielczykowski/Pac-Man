#pragma once
#include "Definitions.h"
//Add mouse/keyboard navigation functionality
class MenuWindow
{
private:
	sf::Sprite background;
	sf::Texture background_texture;
	sf::Text gameName, options[3]; 
	sf::Font font; 

	sf::View menuView;

public:
	MenuWindow(sf::RenderWindow &window);
	~MenuWindow();

	void draw(sf::RenderWindow& window);
};

