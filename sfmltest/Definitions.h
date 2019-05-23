#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include <typeinfo>
#include <cmath>
#include <memory>
#include <windows.h>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 700

#define FONT_PATH "Walk-Around-the-Block.ttf"

#define BACKGROUND_MENU_WIDTH 3592
#define BACKGROUND_MENU_HEIGHT 2612

#define MAP_PIXELS_SIZE 50
#define MAP_OFFSET_X 450	//offsety po³o¿enia planszy na ekranie
#define MAP_OFFSET_Y 75

enum class SpecialPower {
	NONE,
	EAT_ENEMY,
	SLOW_PLAYER,
	SLOW_ENEMY,
	SUPER_SPEED,
	SHOOT,
	SLOW_EAT_ENEMY
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