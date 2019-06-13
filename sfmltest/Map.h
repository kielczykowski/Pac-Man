#pragma once
#include "Definitions.h"

/*! \file Map.h
\brief Plik opisuj�cy elementy mapy rozgrywki.

W pliku napisana jest klasa, kt�ra odpowiada za tworzenie element�w mapy o danych wymiarach, ustawieniu oraz kolorach.
*/

//! Klasa odpowiedzialna za tworzenie element�w mapy.
/*!
Klasa zawiera w sobie kszta�t elementu oparty na prostok�cie, ustawia si� rozmiar elementu, kolor oraz rozmieszczenie na planszy rozgrywki.
*/
class Map
{
private:
	//! Zmienna okre�laj�ca kszta�t.
	/*! Zmienna okre�laj�ca kszta�t elementu na mapie. Do tego pola wpisac mo�na kolor, kszta�t i rozmieszczenie rysowanego elementu.*/
	sf::RectangleShape shape_;
	
public:
	//! Konstruktor klasy Map
	/*! Konstruktor klasy przyjmuje pozcyj�, kszta�t i kolor elementu, kt�ry ma by� stworzony.*/
	Map(sf::RenderWindow& window, sf::Vector2f& position, sf::Vector2f& size,sf::Color color = sf::Color::Green);
	//!Domy�lny Destruktor klasy Map.

	~Map();

	//! Funkcja zwracaj�ca atrybut klasy
	/*! Funkcja zwracaj�ca atrybut klasy shape_ odpowiedzialny, g��wnie za sprawdzenie kolizji z elementem.*/
	sf::RectangleShape getShape() const;

	//! Funkcja rysuj�ca element.
	/*! Funkcja odpowiedzialna za narysowanie elementu w oknie rozgrywki
	\param	window okno, w kt�rym narysowany ma zosta� element*/
	void draw(sf::RenderWindow& window) const;

	//! Funkcja zwracaj�ca wektor mapy
	/*! Funkcja zwracaj�ca wektor element�w klasy potrzebny do stworzenia mapy rozgrywki*/
	static std::vector<Map> stage1(sf::RenderWindow& window);
 

	
};

