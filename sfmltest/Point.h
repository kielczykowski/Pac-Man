#pragma once
#include "Enemy.h"

/*! \file Point.h
\brief Plik opisuj�cy klas� punkt�w.

W pliku napisana jest klasa, kt�ra opisuj�ca atrybuty oraz metody jakie posiadaj� punkty wy�wietlane na mapie podczas rozgrywki.
*/


//! Klasa punkt�w
/*! Klasa odpowiedzialna za implementacj� obiekt�w, kt�re po zetkni�ciu z graczem ulegaj� destrukcji i przyznaj� graczowi punkty.
W klasie okre�lone s� atrybuty, kszta�t i inne cechy oraz moce, kt�re po zbiciu przez przeciwnika mo�e on otrzyma�.*/
class Point
{
protected:
	//! Kszta�t punktu
	/*! Atrybut odpowiedzialny za pozycjonowanie, kszta�towanie oraz rysowanie elementu w oknie rozgrywki.*/
	sf::CircleShape	shape_;

	//! Atrybut specjalnej mocy, kt�r� niesie punk.
	/*! Atrybut odpowiedzialny za stwierdzenie czy punkt niesie ze sob� super moc, kt�r� mo�e przekaza� graczowi.
	\sa SpecialPower*/
	SpecialPower	power_;
	//sf::Sprite body;
	//sf::Texture bodytexture;

public:

	//! Konstruktor klasy.
	/*! Konstruktor odpowiedzialny za stworzenie elementu w danym miejscu okna.
		\param position pozycja elementu w oknie
		\param pow super moc, kt�r� niesie ze sob� punkt
		\param color kolor obiektu na mapie
		\sa SpecialPower*/
	Point(sf::Vector2f& position, const SpecialPower& pow = SpecialPower::NONE, const sf::Color& color= sf::Color::Red);

	//! Funkcja generuj�ca punkty na mapie
	/*! Funkcja zwraca wektor element�w, kt�re wy�wietlane zostan� na Mapie rozgrywki.
		\return zwraca wektor punkt�w rozmieszczonych odpowiednio na mapie*/
	static std::vector<Point> stage1();

	//! Funkcja rysuj�ca obiekt
	/*! Funckja rysuj�ca obiekt na mapie.
		\param window okno, na kt�rym rysowany b�dzie obiekt o danych parametrach.*/
	void draw(sf::RenderWindow& window) const;

	//! Funkcja zwracaj�ca szta�t
	/*! Funkcja zwraca atrybut klasy shape_
		\return zwraca atrybut klasy sf::CircleShape
		\sa shape_*/
	sf::CircleShape getShape() const;

	//! Funkcja zwracaj�ca moc punktu
	/*! Funckcja, kt�ra zwraca super moc, kt�r� niesie punkt,
		\return zwraca atrybut power_ typu SpecialPower
		\sa power_*/
	SpecialPower getPower() const;
};

//virtual ~Point();
//virtual void update(Player& player);

