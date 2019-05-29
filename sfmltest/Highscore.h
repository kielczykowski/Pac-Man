#pragma once
#include "Point.h"
class Highscore
{
private:
	std::vector<ScoreData> data_;
	std::vector<sf::Text> table_;
	sf::Text table_name_;
	sf::Font font_;
public:
	void main(sf::RenderWindow& window, sf::Event& event);
	void downloadHighscores();
	void saveHighscores();
	void initTable();
	void moveTableUp();
	void moveTableDown();
	void addHighscores(ScoreData& highscore);
	void addHighscores(const std::string& name, int points);
	void printHighscores();
	void update(sf::RenderWindow& window); //event handling

	Highscore();
	~Highscore();
};

