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
#include <random> 
#include <cstdlib>
#include <ctime>

/*! \file Definitions.h
	\brief Plik zawieraj�cy define, struct i enumy globalnego zasiegu.

	W pliku zawieraj� si� wszystkie definy powoduj�ce, �e gra jest sterowana kilkoma zmiennymi, kt�rymi u�ytkownik jest w stanie dostosowa� wsp�czynniki do w�asnych wymaga� sprz�towych.
	Ponad to zawiera enum i struct globalnego zasi�gu, kt�re s� kluczowe z punktu widzenia ca�ego programu.
	*/

/*! \def SCREEN_WIDTH
	\brief Makro determinuj�ce szeroko�� okna.

*/

/*! \def SCREEN_HEIGHT
\brief Makro determinuj�ce wysoko�� okna.

*/

/*! \def FONT_PATH
\brief Makro zawieraj�ce w sobie �cie�k� do czcionki.

*/

/*! \def HIGHSCORES_PATH
\brief Makro zawieraj�ce w sobie �cie�k� do pliku z najlepszymi wynikami z gry

*/

/*! \def BACKGROUND_MENU_WIDTH
\brief Makro determinuj�ce szeroko�� zdj�cia w tle MENU.

*/
/*! \def BACKGROUND_MENU_HEIGHT
\brief Makro determinuj�ce wysoko�� zdj�cia w tle MENU.

*/

/*! \def MAP_PIXELS_SIZE
\brief Makro determinuj�ce rozmiar element�w mapy w pixelach.

*/

/*! \def MAP_OFFSET_X
\brief Makro determinuj�ce offset mapy rozgrywki w kierunku poziomym.

*/
/*! \def MAP_OFFSET_Y
\brief Makro determinuj�ce offset mapy rozgrywki w kierunku pinowym.

*/

/*! \def POWER_VALIDATION_TIME
\brief Makro determinuj�ce czas, przez kt�ry dzia�a super moc gracza.

*/

/*! \enum SpecialPower
\brief Typ wyliczeniowy determinuj�cy super moce dost�pne w grze.

*/

/*! \struct ScoreData
\brief Struktura przechowuj�ca dane po zako�czeniu rozgrywki.

*/



#define SCREEN_WIDTH			1000
#define SCREEN_HEIGHT			700

#define FONT_PATH				"Walk-Around-the-Block.ttf"
#define HIGHSCORES_PATH			"./Highscores.txt"

#define BACKGROUND_MENU_WIDTH	3592
#define BACKGROUND_MENU_HEIGHT	2612

#define MAP_PIXELS_SIZE			50
#define MAP_OFFSET_X			450	//offsety po�o�enia planszy na ekranie
#define MAP_OFFSET_Y			75
#define POWER_VALIDATION_TIME	10

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
//wyci�gn�� logik� playera do GameMastera, dorobi� gettery settery do Playera i w ten spos�b robi� obs�ug� event�w bo inaczej escape dzia�a po 15 sekundach w tych petlach XDXDDX
//still problem, framerate jumps 2 high

//TODO:
//wy�wietlanie wyniku punkt�w w trakcie gry													==DONE
//Pauza w grze!																				==DONE
//Pobieranie nicku od zawodnika																==DONE
//stworzenie przeciwnik�w																	==DONE
//algorytm przeciwnik�w																		
//opracowanie dzia�ania supermocy Pacmana -> czasowe ustawianie jego mocy					==DONE
//stworzenie rankingu w highscores -> prosta baza danych czy mo�e plik bitowy				==DONE
//kolejne plansze
//przemyslenie sterowania -> za wolno mieli program
//framerate-independent gameplay !
//ogarni�cie problemu View
//REWIZJA KODU bo do niczego to nie podobne jest XD
//!!!!!!!!!
//add Scary mode to enemies- podczas poweru pacmana, �eby stworki ucieka�y
//t�o na innych oknach te�																	==DONE
//doda� "YOU LOSE" po przegraniu gierki														==DONE
//add after enemy colision 5 seconds where only player can move and intersection with enemies doesnt kill him(transparent them a little bit)
//refaktoryzacja mastera do logic

//refactor:
//void GameMaster::drawUpdates(sf::RenderWindow& window);
//void Highscore::downloadHighscores();

//PROBLEMS
//void GameLogic::afterGameLogic(sf::RenderWindow& window, sf::Event& event, sf::String& nick);				Esc,bspc problem of getting unicode and writing it to string :(
//void GameMaster::main(sf::RenderWindow& window, sf::Event& event, Highscore& hgh)							empty string is added to highscores list
//bool GameObject::doesCollide(sf::CircleShape& shape) const												polymorphism problem
//void Enemy::update																						placeholder, maybe delete
//OBJECT INTERSECTION !!!!!!! - musze przerobic to ruszanie sie bo to beka jakas jest	