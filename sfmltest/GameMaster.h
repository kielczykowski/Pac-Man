#pragma once
#include "GameLogic.h"

class GameMaster
{
private: 
	//not used ATM
	bool		exit;	// if game is paused and escape is clicked again -> loop exits
	bool		pause; // pausing game with escape -> escape sets pause to true
	sf::Clock	clock_;
	sf::Time	time_;
	//

	int			score_;
	int			lifes_;

public:
	GameMaster();
	~GameMaster();
	void init();
	void main(sf::RenderWindow& window, sf::Event& event);

	void spin(sf::RenderWindow& window, sf::Event& event);
	//updates score by value or addScore?
	void updateScore(int&& value = 100);
	void updateLifes(int&& value = -1);
	bool isDead();


	int getScore(); //returns score after game2 
	bool getPause();
	bool getExit();
	sf::String getName(); //returns nick after game


};

