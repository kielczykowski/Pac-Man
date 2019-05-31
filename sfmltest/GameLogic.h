#pragma once
#include "Highscore.h"

class GameLogic
{
private:
	bool valid_power_;
	bool pause_;
	bool exit_;
	bool save_score_;
	sf::Clock clock_;

	//not used atm
	sf::Time time_;
	
public:
	GameLogic();
	~GameLogic();

	bool getPause() const;
	bool getExit() const;
	bool getSaveScore() const;
	bool getValidPower() const;
	void setPause(bool logic);
	void setExit(bool logic);
	void setSaveScore(bool logic);
	void setValidPower(bool logic);
	void startClock();
	float getElapsedTime();


	void playerLogic(sf::RenderWindow& window, Player& player, sf::Event& event, std::vector<Map>& map);
	void pausedGameLogic(sf::RenderWindow& window, sf::Event& event);
	void afterGameLogic(sf::RenderWindow& window, sf::Event& event, sf::String& nick);
};

