#pragma once
#include "Player.h"

/*! \file Enemy.h
\brief Plik opisuj�cy klas� przeciwnika.

W pliku napisana jest klasa, kt�ra opisuj�ca atrybuty oraz metody jakie posiada przeciwnik podczas rozgyrwki.
*/

//! Klasa Przeciwnika.
/*! Klasa opisuj�ca atrybuty oraz metody, kt�re unikalnie posiada przeciwnik. Klasa dziedziczy po klasie GameObject.
\sa GameObject*/
class Enemy : public Player
{
private: 
	sf::Clock clock_;
public:
	//! Konstruktor klasy przeciwnika.
	/*! Konstruktor wpisuje warto�ci pocz�tkowe podczas tworzenia obiektu przeciwnika zgodnie z parametrami okre�lonymi jako argumenty funckji.
	W konstruktorze 
		\param window okno rozgrywki
		\param path �cie�ka do tekstury gracza
		\param position pozycja pocz�tkowego pojawienia si� elementu na mapie
		\param speed pr�dko�� bazowa elemntu
		\sa GameObject*/
	Enemy(sf::RenderWindow& window, sf::String path, sf::Vector2f& position, float speed = 1.f);

	//! Destruktor Klasy
	/*! Destruktor Klasy.*/
	~Enemy();

	//! Funkcja zmainy koloru przeciwnika.
	/*! Funkcja odpowiedzialna jest za zmian� koloru przeciwnika w momencie, gdy gracz posiada super moc.
	Gdy kolor jest zmieniony gracz ma mo�liwo�� ataku przeciwnika i zdobycia za niego punkt�w.
		\param color kolor, kt�ry ustawiany jest przeciwnikowi*/
	void changeColor(const sf::Color& color);
	
	//void update(sf::RenderWindow& window, sf::Event& event, std::vector<Map>& map) override;

	void startClock();
	float getElapsedTime();
};

