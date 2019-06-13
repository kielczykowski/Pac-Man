#pragma once
#include "GameObject.h"
/*! \file Player.h
\brief Plik opisuj�cy klas� gracza.

W pliku napisana jest klasa, kt�ra opisuj�ca atrybuty oraz metody jakie posiada gracz podczas rozgyrwki.
*/
 
//! Klasa gracza
/*! Klasa opisuj�ca atrybuty oraz metody, kt�re unikalnie posiada gracz. Klasa dziedziczy po klasie GameObject.
	\sa GameObject*/
class Player : public GameObject
{
private: 
	//! Atrybut specjalnej mocy gracza.
	/*! Atrybut odpowiedzialny za stwierdzenie czy gracz ma aktualnie super moc oraz stwierdzenie logiki w razie interakcji z przeciwnikiem.
		\sa SpecialPower*/
	SpecialPower power_;

	//! Atrybut �ledzenia intencij gracza
	/*! Atrybut zapami�tuj�cy intencje gracza. Gdy gracz nie ma mo�liwo�ci skr�tu w g�r�, atrybut posiada warto�� true.
	W momencie, gdy mo�liwy jest ruch w danym kierunku zmienna osi�ga warto�� false i nast�puje zmiana kierunku poruszania gracza.*/
	bool	wantUpwards_;

	//! Atrybut �ledzenia intencij gracza
	/*! Atrybut zapami�tuj�cy intencje gracza. Gdy gracz nie ma mo�liwo�ci skr�tu w d�, atrybut posiada warto�� true.
	W momencie, gdy mo�liwy jest ruch w danym kierunku zmienna osi�ga warto�� false i nast�puje zmiana kierunku poruszania gracza.*/
	bool	wantDownwards_;

	//! Atrybut �ledzenia intencij gracza
	/*! Atrybut zapami�tuj�cy intencje gracza. Gdy gracz nie ma mo�liwo�ci skr�tu w lewo, atrybut posiada warto�� true.
	W momencie, gdy mo�liwy jest ruch w danym kierunku zmienna osi�ga warto�� false i nast�puje zmiana kierunku poruszania gracza.*/
	bool	wantLeft_;

	//! Atrybut �ledzenia intencij gracza
	/*! Atrybut zapami�tuj�cy intencje gracza. Gdy gracz nie ma mo�liwo�ci skr�tu w prawo, atrybut posiada warto�� true.
	W momencie, gdy mo�liwy jest ruch w danym kierunku zmienna osi�ga warto�� false i nast�puje zmiana kierunku poruszania gracza.*/
	bool	wantRight_;


public:
	//! Konstruktor klasy .
	/*! Konstruktor odpowiedzialny za wpisanie warto�ci pocz�tkowych gracza. 
	Ustalona zostaje pozycja, kszta�t i tekstura oraz pr�dko�c bazowa gracza.
	W konstruktorze wywo�ywany jest konstruktor klasy bazowej GameObject.
		\param window okno rozgrywki
		\param path �cie�ka do wczytania tekstury gracza
		\param position pozycja pocz�tkowa, na kt�rej pojawi� ma si� posta� gracza
		\param speed pr�dko�� bazowa gracza 
		\sa GameObject*/
	Player(sf::RenderWindow& window, sf::String path, sf::Vector2f& position, float speed = 1.f);

	//! Destruktor klasy.
	/*! Destruktor klasy.*/
	~Player();

	//! Funkcja ustawiaj�ca intencje gracza.
	/*! Funkcja odpowiedzialna za ustawienie atrybutu �ledzenia intencji oraz mo�liwo�ci skr�tu gracza w g�r�.
		\param logic warto�� logiczna true lub false odpowiedzialna za przypisanie atrybutowi klasy wantUpwards_.
		\sa wantUpwards_*/
	void setWantUp(const bool& logic);

	//! Funkcja ustawiaj�ca intencje gracza.
	/*! Funkcja odpowiedzialna za ustawienie atrybutu �ledzenia intencji oraz mo�liwo�ci skr�tu gracza w d�.
	\param logic warto�� logiczna true lub false odpowiedzialna za przypisanie atrybutowi klasy wantDownwards_.
	\sa wantDownwards_*/
	void setWantDown(const bool& logic);

	//! Funkcja ustawiaj�ca intencje gracza
	/*! Funkcja odpowiedzialna za ustawienie atrybutu �ledzenia intencji oraz mo�liwo�ci skr�tu gracza w lewo.
	\param logic warto�� logiczna true lub false odpowiedzialna za przypisanie atrybutowi klasy wantLeft_.
	\sa wantLeft_*/
	void setWantLeft(const bool& logic);

	//! Funkcja ustawiaj�ca intencje gracza.
	/*! Funkcja odpowiedzialna za ustawienie atrybutu �ledzenia intencji oraz mo�liwo�ci skr�tu gracza w prawo.
	\param logic warto�� logiczna true lub false odpowiedzialna za przypisanie atrybutowi klasy wantRight_.
	\sa wantRight_*/
	void setWantRight(const bool& logic);

	//! Funkcja ustawiaj�ca moc gracza.
	/*! Funkcja odpowiedzialna za ustawienie atrybutu mocy gracza.
		\param power moc, kt�r� przypisuje si� graczowi
		\sa power_*/
	void setPower(const SpecialPower& power);
	
	//! Funkcja zwracaj�ca intencje gracza
	/*! Funckja zwraca aktualny stan atrybutu wantUpwards_.
		\sa wantUpwards_*/
	bool getWantUp() const;

	//! Funkcja zwracaj�ca intencje gracza
	/*! Funckja zwraca aktualny stan atrybutu wantDownwards_.
	\sa wantDownwards_*/
	bool getWantDown() const;

	//! Funkcja zwracaj�ca intencje gracza
	/*! Funckja zwraca aktualny stan atrybutu wantLeft_.
	\sa wantLeft_*/
	bool getWantLeft() const;

	//! Funkcja zwracaj�ca intencje gracza
	/*! Funckja zwraca aktualny stan atrybutu wantRight_.
	\sa wantRight_*/
	bool getWantRight() const;

	//!Funkcja zwracaj�ca moc gracza
	/*! Funckaj zwraca aktualny stan atrybutu power_.
		\sa power_*/
	SpecialPower getPower() const;


	void getStates();


};

