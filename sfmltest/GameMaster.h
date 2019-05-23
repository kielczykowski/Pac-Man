#pragma once
#include "Point.h"

class GameMaster
{
private: 
	bool exit;	// if game is paused and escape is clicked again -> loop exits
	bool pause; // pausing game with escape -> escape sets pause to true
	int score;
	int lifes;
	sf::Clock clock;
	sf::Time time;
public:
	GameMaster();
	~GameMaster();

	//updates score by value or addScore?
	void updateScore(int&& value = 100);
	void updateLifes(int&& value = -1);
	bool isDead();
	void init();
	void main(sf::RenderWindow& window, sf::Event& event);
	void spin(sf::RenderWindow& window, sf::Event& event);

	int getScore(); //returns score after game2 
	bool getPause();
	bool getExit();
	sf::String getName(); //returns nick after game


};

