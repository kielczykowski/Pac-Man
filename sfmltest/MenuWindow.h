#pragma once
#include "GameMaster.h"
//Add mouse/keyboard navigation functionality

/*! \file MenuWindow.h
\brief Plik opisuj¹cy wygl¹d Menu g³ównego

W pliku napisana jest klasa odpowiedzialna za obs³u¿enie logiki rozgrywki.
*/


//! Klasa Menu g³ównego
/*! Klasa odpowiedzialna za rysowanie oraz obs³ugê okna Menu g³ównego*/
class MenuWindow
{
private:

	//! T³o gry
	/*! Argument przetrzymuj¹cy t³o wraz z jego wymiarami i pozycj¹.*/
	sf::Sprite	background_;

	//! Tekstura t³a
	/*! Argument przetrzymuje teksturê (obrazek) stosowany w tle.*/
	sf::Texture	background_texture_;

	//! Argumenty tekstowe
	/*! Arugmenty posiadaj¹ce odpowiednie teksty oraz rozmieszczenie w oknie rozgrywki.
	Zawieraj¹ nazwê gry oraz dostêpne opcje wyboru dalszej rozgrywki.*/
	sf::Text	game_name_, options_[3]; 

	//! Argument czcionki
	/*! Argument przetrzymuje wczytan¹ czcionkê*/
	sf::Font	font_; 

	sf::View		menuView;
	//sf::Vector2f wordlPos;

public:

	//! Konstruktor
	/*! W kontruktorze definiowane oraz rozmieszczone s¹ wsyzstkie elementy przy powo³ywaniu obiektu.
		\param window okno, w którym odbywac siê bêdzie rozgrywka*/
	MenuWindow(sf::RenderWindow &window);

	//! Destruktor 
	~MenuWindow();


	//! Funkcja rysuj¹ca elementy w oknie
	/*! \param window okno gry*/
	void draw(sf::RenderWindow& window) const;

	//! Funkcja obs³uguj¹ca zdarzenia w oknie
	/*! Funkcja sprawdza czy u¿ytkownik nie wykonuje zdefiniowanej akcj, któr awp³ywa na dalsze dzia³anie programu
		\param window okno gry
		\param event obiekt obs³ugi interakcji u¿ytkownika
		\param game obiekt odpowiedzialny za rozpoczêcie i trwanie rozgrywki
		\param hgh obiekt przetrzymuj¹cy wyniki rozgrywek*/
	void checkStatus(sf::RenderWindow&window, sf::Event& event, GameMaster& game, Highscore& hgh);		//event handling

	//! Funkcja ustawiaj¹ca aktualny stan okna
	/*! Funkcja ustawia stan, który determinuje co powinno wydarzyæ siê po wyst¹pieniu interakcji u¿ytkownika
		\param window okno gry*/
	void setStatus(sf::RenderWindow& window);													//setting which option is chosen

	//! Funckja zwracaj¹ca status okna
	int	getStatus() const;																		//getting chosen element id 

	//! Funkcja zwracaj¹ca t³o
	sf::Sprite getBackground() const;


};

