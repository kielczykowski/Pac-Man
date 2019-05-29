#include "stdafx.h"
#include "Highscore.h"


Highscore::Highscore()
{
	assert(font_.loadFromFile(FONT_PATH));
	downloadHighscores();
	table_name_.setString("Highscores Table :D");
	table_name_.setFont(font_);
	table_name_.setFillColor(sf::Color::Yellow);
	table_name_.setCharacterSize(MAP_PIXELS_SIZE * 3);
	table_name_.setPosition(MAP_OFFSET_X* 0.5f , MAP_OFFSET_Y);
}


Highscore::~Highscore()
{
}


void Highscore::initTable(){
	table_.clear();
	//lambda expression to sort custom data objects
	std::sort(data_.begin(), data_.end(), [](const ScoreData& a, const ScoreData& b){
		return a.points > b.points;
	});

	int i = 1;
	for (auto& obj : data_) {
		sf::Text txt;
		std::stringstream stream;
		stream << i << ".\t\t" << obj.nick << "\t\t" << obj.points;
		txt.setString(stream.str());
		txt.setFont(font_);
		txt.setFillColor(sf::Color::Yellow);
		txt.setCharacterSize(MAP_PIXELS_SIZE*3/4);
		txt.setPosition(sf::Vector2f(MAP_OFFSET_X + MAP_PIXELS_SIZE, MAP_OFFSET_Y + (5+i) * MAP_PIXELS_SIZE));
		table_.push_back(txt);
		i++;
	}

}

void Highscore::update(sf::RenderWindow& window) {
	window.draw(table_name_);
	for (auto& obj : table_){
		if (!(obj.getPosition().y < MAP_OFFSET_Y + 6 * MAP_PIXELS_SIZE || obj.getPosition().y >  MAP_OFFSET_Y + 17* MAP_PIXELS_SIZE)){
			window.draw(obj);
		}

	}
}

void Highscore::moveTableUp(){
	if (table_.front().getPosition().y >= MAP_OFFSET_Y + 6 * MAP_PIXELS_SIZE) {
		return;
	}

	for (auto& obj : table_) {
		obj.move(sf::Vector2f(0, MAP_PIXELS_SIZE * 3 / 4));
	}
}
void Highscore::moveTableDown(){
	if (table_.back().getPosition().y <= MAP_OFFSET_Y + 17 * MAP_PIXELS_SIZE) {
		return;
	}

	for (auto& obj : table_) {
		obj.move(sf::Vector2f(0, -(MAP_PIXELS_SIZE * 3 / 4)));
	}
}

//working XD
void Highscore::downloadHighscores(){
	std::string line;
	std::ifstream file(HIGHSCORES_PATH);
	if (file.is_open()){
		while (std::getline(file, line)){
			std::stringstream ss(line);
			std::string token;
			ScoreData data_buffer;
			std::getline(ss, token, ' ');
			data_buffer.nick = token;
			std::getline(ss, token, '\n');
			data_buffer.points = std::stoi(token);
			data_.push_back(data_buffer);
		}
		file.close();
	}
}

void Highscore::saveHighscores(){
	std::stringstream stream;
	std::ofstream file(HIGHSCORES_PATH); 
	if (file.is_open()) {
		for (auto obj : data_){
			file << obj.nick << " " << obj.points << std::endl;
		}
		file.close();
	}
	else
		std::cout << "HIGHSCORES FILE PROBLEM" << std::endl;
	
}

void Highscore::addHighscores(const std::string& name, int points){
	ScoreData object;
	object.nick = name;
	object.points = points;
	data_.push_back(object);
}

void Highscore::printHighscores(){
	std::cout << "Highscores" << std::endl;
	for (auto obj : data_){
		std::cout << "nick: " << obj.nick << "\tpoints: " << obj.points << std::endl;
	}
}

//cos nie dziala, nic nie dziala
void Highscore::main(sf::RenderWindow& window, sf::Event& event) {
	window.clear();
	initTable();
	bool exit = false;
	while (!exit){
		window.clear();
		update(window);
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::KeyPressed:
				switch (event.key.code) {
				case sf::Keyboard::Escape:
					exit = true;
					break;
				}
				break;
			case sf::Event::MouseWheelMoved:
				if (event.mouseWheel.delta < 0)
					moveTableDown();
				else{
					moveTableUp();
				}
				break;

			}
		}
		window.display();
	}
}
