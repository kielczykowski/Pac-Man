#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include <typeinfo>
#include <cmath>
#include <memory>
#include <windows.h>
#include <sstream>
#include <string>
#include <fstream>

#define SCREEN_WIDTH			1000
#define SCREEN_HEIGHT			700

#define FONT_PATH				"Walk-Around-the-Block.ttf"
#define HIGHSCORES_PATH			"./Highscores.txt"

#define BACKGROUND_MENU_WIDTH	3592
#define BACKGROUND_MENU_HEIGHT	2612

#define MAP_PIXELS_SIZE			50
#define MAP_OFFSET_X			450	//offsety po³o¿enia planszy na ekranie
#define MAP_OFFSET_Y			75
#define POWER_VALIDATION_TIME	5

enum class SpecialPower {
	NONE,
	SLOW_EAT_ENEMY
};

struct ScoreData{
	std::string nick;
	int points;
};

//MenuWindow
//Every time window gets resized, graphically it works, but global bounds are dependent from code-set HEIGHT and Position
//Reconsider steering by keyboard and setting resizable window as false (future gameplay issues :( )
//FULLSCREEN IS REMEDY!

//GameObject
//consider making sf::texture bodytexture static for all Player and Enemy objects

//consider using non-frame dependent gameplay

//class Point -> NormalPoint, SpecialPoint(special will have enums with powers

//LOOPS
//wyci¹gn¹æ logikê playera do GameMastera, dorobiæ gettery settery do Playera i w ten sposób robiæ obs³ugê eventów bo inaczej escape dzia³a po 15 sekundach w tych petlach XDXDDX
//still problem, framerate jumps 2 high

//TODO:
//wyœwietlanie wyniku punktów w trakcie gry													==DONE
//Pauza w grze!																				==DONE
//Pobieranie nicku od zawodnika																==DONE
//stworzenie przeciwników																	==DONE
//algorytm przeciwników																		
//opracowanie dzia³ania supermocy Pacmana -> czasowe ustawianie jego mocy					==DONE
//stworzenie rankingu w highscores -> prosta baza danych czy mo¿e plik bitowy				==DONE
//kolejne plansze
//przemyslenie sterowania -> za wolno mieli program
//framerate-independent gameplay !
//ogarniêcie problemu View
//REWIZJA KODU bo do niczego to nie podobne jest XD
//!!!!!!!!!
//add Scary mode to enemies- podczas poweru pacmana, ¿eby stworki ucieka³y

//refactor:
//void GameMaster::drawUpdates(sf::RenderWindow& window);
//void Highscore::downloadHighscores();

//PROBLEMS
//void GameLogic::afterGameLogic(sf::RenderWindow& window, sf::Event& event, sf::String& nick);				Esc,bspc problem of getting unicode and writing it to string :(
//void GameMaster::main(sf::RenderWindow& window, sf::Event& event, Highscore& hgh)							empty string is added to highscores list
//bool GameObject::doesCollide(sf::CircleShape& shape) const												polymorphism problem
//void Enemy::update																						placeholder, maybe delete