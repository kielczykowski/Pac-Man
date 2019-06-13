#pragma once
#include "Player.h"

/*! \file Enemy.h
\brief Plik opisuj¹cy klasê przeciwnika.

W pliku napisana jest klasa, która opisuj¹ca atrybuty oraz metody jakie posiada przeciwnik podczas rozgyrwki.
*/

//! Klasa Przeciwnika.
/*! Klasa opisuj¹ca atrybuty oraz metody, które unikalnie posiada przeciwnik. Klasa dziedziczy po klasie GameObject.
\sa GameObject*/
class Enemy : public Player
{
private: 
	sf::Clock clock_;
public:
	//! Konstruktor klasy przeciwnika.
	/*! Konstruktor wpisuje wartoœci pocz¹tkowe podczas tworzenia obiektu przeciwnika zgodnie z parametrami okreœlonymi jako argumenty funckji.
	W konstruktorze 
		\param window okno rozgrywki
		\param path œcie¿ka do tekstury gracza
		\param position pozycja pocz¹tkowego pojawienia siê elementu na mapie
		\param speed prêdkoœæ bazowa elemntu
		\sa GameObject*/
	Enemy(sf::RenderWindow& window, sf::String path, sf::Vector2f& position, float speed = 1.f);

	//! Destruktor Klasy
	/*! Destruktor Klasy.*/
	~Enemy();

	//! Funkcja zmainy koloru przeciwnika.
	/*! Funkcja odpowiedzialna jest za zmianê koloru przeciwnika w momencie, gdy gracz posiada super moc.
	Gdy kolor jest zmieniony gracz ma mo¿liwoœæ ataku przeciwnika i zdobycia za niego punktów.
		\param color kolor, który ustawiany jest przeciwnikowi*/
	void changeColor(const sf::Color& color);
	
	//void update(sf::RenderWindow& window, sf::Event& event, std::vector<Map>& map) override;

	void startClock();
	float getElapsedTime();
};

