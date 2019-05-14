#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include <typeinfo>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 700

#define FONT_PATH "Walk-Around-the-Block.ttf"

#define BACKGROUND_MENU_WIDTH 3592
#define BACKGROUND_MENU_HEIGHT 2612

//MenuWindow
//Every time window gets resized, graphically it works, but global bounds are dependent from code-set HEIGHT and Position
//Reconsider steering by keyboard and setting resizable window as false (future gameplay issues :( )
//FULLSCREEN IS REMEDY!