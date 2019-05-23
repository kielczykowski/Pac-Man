#pragma once
#include "Point.h"

class GameLogic
{
private:
	bool pause;
	bool exit;
public:
	GameLogic();
	~GameLogic();

	bool getPause();
	bool getExit();
	void setPause(bool logic);
	void setExit(bool logic);

	void playerLogic(sf::RenderWindow& window, Player& player, sf::Event& event, std::vector<Map>& map);
};

