#pragma once
#include "Highscore.h"

class GameLogic
{
private:
	bool pause_;
	bool exit_;
public:
	GameLogic();
	~GameLogic();

	bool getPause() const;
	bool getExit() const;
	void setPause(bool logic);
	void setExit(bool logic);

	void playerLogic(sf::RenderWindow& window, Player& player, sf::Event& event, std::vector<Map>& map);
	void pausedGameLogic(sf::RenderWindow& window, sf::Event& event);
};

