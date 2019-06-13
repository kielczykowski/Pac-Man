#pragma once
#include "Enemy.h"

/*! \file Point.h
\brief Plik opisuj¹cy klasê punktów.

W pliku napisana jest klasa, która opisuj¹ca atrybuty oraz metody jakie posiadaj¹ punkty wyœwietlane na mapie podczas rozgrywki.
*/


//! Klasa punktów
/*! Klasa odpowiedzialna za implementacjê obiektów, które po zetkniêciu z graczem ulegaj¹ destrukcji i przyznaj¹ graczowi punkty.
W klasie okreœlone s¹ atrybuty, kszta³t i inne cechy oraz moce, które po zbiciu przez przeciwnika mo¿e on otrzymaæ.*/
class Point
{
protected:
	//! Kszta³t punktu
	/*! Atrybut odpowiedzialny za pozycjonowanie, kszta³towanie oraz rysowanie elementu w oknie rozgrywki.*/
	sf::CircleShape	shape_;

	//! Atrybut specjalnej mocy, któr¹ niesie punk.
	/*! Atrybut odpowiedzialny za stwierdzenie czy punkt niesie ze sob¹ super moc, któr¹ mo¿e przekazaæ graczowi.
	\sa SpecialPower*/
	SpecialPower	power_;
	//sf::Sprite body;
	//sf::Texture bodytexture;

public:

	//! Konstruktor klasy.
	/*! Konstruktor odpowiedzialny za stworzenie elementu w danym miejscu okna.
		\param position pozycja elementu w oknie
		\param pow super moc, któr¹ niesie ze sob¹ punkt
		\param color kolor obiektu na mapie
		\sa SpecialPower*/
	Point(sf::Vector2f& position, const SpecialPower& pow = SpecialPower::NONE, const sf::Color& color= sf::Color::Red);

	//! Funkcja generuj¹ca punkty na mapie
	/*! Funkcja zwraca wektor elementów, które wyœwietlane zostan¹ na Mapie rozgrywki.
		\return zwraca wektor punktów rozmieszczonych odpowiednio na mapie*/
	static std::vector<Point> stage1();

	//! Funkcja rysuj¹ca obiekt
	/*! Funckja rysuj¹ca obiekt na mapie.
		\param window okno, na którym rysowany bêdzie obiekt o danych parametrach.*/
	void draw(sf::RenderWindow& window) const;

	//! Funkcja zwracaj¹ca szta³t
	/*! Funkcja zwraca atrybut klasy shape_
		\return zwraca atrybut klasy sf::CircleShape
		\sa shape_*/
	sf::CircleShape getShape() const;

	//! Funkcja zwracaj¹ca moc punktu
	/*! Funckcja, która zwraca super moc, któr¹ niesie punkt,
		\return zwraca atrybut power_ typu SpecialPower
		\sa power_*/
	SpecialPower getPower() const;
};

//virtual ~Point();
//virtual void update(Player& player);

