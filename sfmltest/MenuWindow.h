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
	//sf::Vector2f wordlPos;

public:
	MenuWindow(sf::RenderWindow &window);
	~MenuWindow();

	void moveUp();
	void moveDown();

	void draw(sf::RenderWindow& window);
	void setStatus(sf::RenderWindow& window);	//setting which option is chosen
	int getStatus();	//getting chosen element id 
	void checkStatus(sf::RenderWindow&window, sf::Event& event);	//event handling

};

