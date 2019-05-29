#pragma once
#include "Highscore.h"

class GameLogic
{
private:
	bool pause_;
	bool exit_;
	bool save_score_;
public:
	GameLogic();
	~GameLogic();

	bool getPause() const;
	bool getExit() const;
	bool getSaveScore() const;
	void setPause(bool logic);
	void setExit(bool logic);
	void setSaveScore(bool logic);


	void playerLogic(sf::RenderWindow& window, Player& player, sf::Event& event, std::vector<Map>& map);
	void pausedGameLogic(sf::RenderWindow& window, sf::Event& event);
	void afterGameLogic(sf::RenderWindow& window, sf::Event& event, sf::String& nick);
};

