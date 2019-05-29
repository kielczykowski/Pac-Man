#pragma once
#include "GameMaster.h"
//Add mouse/keyboard navigation functionality
class MenuWindow
{
private:
	sf::Sprite	background_;
	sf::Texture	background_texture_;
	sf::Text	game_name_, options_[3]; 
	sf::Font	font_; 

	sf::View		menuView;
	//sf::Vector2f wordlPos;

public:
	MenuWindow(sf::RenderWindow &window);
	~MenuWindow();

	void draw(sf::RenderWindow& window) const;

	void checkStatus(sf::RenderWindow&window, sf::Event& event, GameMaster& game, Highscore& hgh) const;		//event handling
	void setStatus(sf::RenderWindow& window);													//setting which option is chosen
	int	getStatus() const;																		//getting chosen element id 


};

