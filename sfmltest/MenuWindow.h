#pragma once
#include "GameMaster.h"
//Add mouse/keyboard navigation functionality

/*! \file MenuWindow.h
\brief Plik opisuj�cy wygl�d Menu g��wnego

W pliku napisana jest klasa odpowiedzialna za obs�u�enie logiki rozgrywki.
*/


//! Klasa Menu g��wnego
/*! Klasa odpowiedzialna za rysowanie oraz obs�ug� okna Menu g��wnego*/
class MenuWindow
{
private:

	//! T�o gry
	/*! Argument przetrzymuj�cy t�o wraz z jego wymiarami i pozycj�.*/
	sf::Sprite	background_;

	//! Tekstura t�a
	/*! Argument przetrzymuje tekstur� (obrazek) stosowany w tle.*/
	sf::Texture	background_texture_;

	//! Argumenty tekstowe
	/*! Arugmenty posiadaj�ce odpowiednie teksty oraz rozmieszczenie w oknie rozgrywki.
	Zawieraj� nazw� gry oraz dost�pne opcje wyboru dalszej rozgrywki.*/
	sf::Text	game_name_, options_[3]; 

	//! Argument czcionki
	/*! Argument przetrzymuje wczytan� czcionk�*/
	sf::Font	font_; 

	sf::View		menuView;
	//sf::Vector2f wordlPos;

public:

	//! Konstruktor
	/*! W kontruktorze definiowane oraz rozmieszczone s� wsyzstkie elementy przy powo�ywaniu obiektu.
		\param window okno, w kt�rym odbywac si� b�dzie rozgrywka*/
	MenuWindow(sf::RenderWindow &window);

	//! Destruktor 
	~MenuWindow();


	//! Funkcja rysuj�ca elementy w oknie
	/*! \param window okno gry*/
	void draw(sf::RenderWindow& window) const;

	//! Funkcja obs�uguj�ca zdarzenia w oknie
	/*! Funkcja sprawdza czy u�ytkownik nie wykonuje zdefiniowanej akcj, kt�r awp�ywa na dalsze dzia�anie programu
		\param window okno gry
		\param event obiekt obs�ugi interakcji u�ytkownika
		\param game obiekt odpowiedzialny za rozpocz�cie i trwanie rozgrywki
		\param hgh obiekt przetrzymuj�cy wyniki rozgrywek*/
	void checkStatus(sf::RenderWindow&window, sf::Event& event, GameMaster& game, Highscore& hgh);		//event handling

	//! Funkcja ustawiaj�ca aktualny stan okna
	/*! Funkcja ustawia stan, kt�ry determinuje co powinno wydarzy� si� po wyst�pieniu interakcji u�ytkownika
		\param window okno gry*/
	void setStatus(sf::RenderWindow& window);													//setting which option is chosen

	//! Funckja zwracaj�ca status okna
	int	getStatus() const;																		//getting chosen element id 

	//! Funkcja zwracaj�ca t�o
	sf::Sprite getBackground() const;


};

