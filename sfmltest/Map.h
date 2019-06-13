#pragma once
#include "Definitions.h"

/*! \file Map.h
\brief Plik opisuj¹cy elementy mapy rozgrywki.

W pliku napisana jest klasa, która odpowiada za tworzenie elementów mapy o danych wymiarach, ustawieniu oraz kolorach.
*/

//! Klasa odpowiedzialna za tworzenie elementów mapy.
/*!
Klasa zawiera w sobie kszta³t elementu oparty na prostok¹cie, ustawia siê rozmiar elementu, kolor oraz rozmieszczenie na planszy rozgrywki.
*/
class Map
{
private:
	//! Zmienna okreœlaj¹ca kszta³t.
	/*! Zmienna okreœlaj¹ca kszta³t elementu na mapie. Do tego pola wpisac mo¿na kolor, kszta³t i rozmieszczenie rysowanego elementu.*/
	sf::RectangleShape shape_;
	
public:
	//! Konstruktor klasy Map
	/*! Konstruktor klasy przyjmuje pozcyjê, kszta³t i kolor elementu, który ma byæ stworzony.*/
	Map(sf::RenderWindow& window, sf::Vector2f& position, sf::Vector2f& size,sf::Color color = sf::Color::Green);
	//!Domyœlny Destruktor klasy Map.

	~Map();

	//! Funkcja zwracaj¹ca atrybut klasy
	/*! Funkcja zwracaj¹ca atrybut klasy shape_ odpowiedzialny, g³ównie za sprawdzenie kolizji z elementem.*/
	sf::RectangleShape getShape() const;

	//! Funkcja rysuj¹ca element.
	/*! Funkcja odpowiedzialna za narysowanie elementu w oknie rozgrywki
	\param	window okno, w którym narysowany ma zostaæ element*/
	void draw(sf::RenderWindow& window) const;

	//! Funkcja zwracaj¹ca wektor mapy
	/*! Funkcja zwracaj¹ca wektor elementów klasy potrzebny do stworzenia mapy rozgrywki*/
	static std::vector<Map> stage1(sf::RenderWindow& window);
 

	
};

