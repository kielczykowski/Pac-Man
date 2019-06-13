#pragma once
#include "GameObject.h"
/*! \file Player.h
\brief Plik opisuj¹cy klasê gracza.

W pliku napisana jest klasa, która opisuj¹ca atrybuty oraz metody jakie posiada gracz podczas rozgyrwki.
*/
 
//! Klasa gracza
/*! Klasa opisuj¹ca atrybuty oraz metody, które unikalnie posiada gracz. Klasa dziedziczy po klasie GameObject.
	\sa GameObject*/
class Player : public GameObject
{
private: 
	//! Atrybut specjalnej mocy gracza.
	/*! Atrybut odpowiedzialny za stwierdzenie czy gracz ma aktualnie super moc oraz stwierdzenie logiki w razie interakcji z przeciwnikiem.
		\sa SpecialPower*/
	SpecialPower power_;

	//! Atrybut œledzenia intencij gracza
	/*! Atrybut zapamiêtuj¹cy intencje gracza. Gdy gracz nie ma mo¿liwoœci skrêtu w górê, atrybut posiada wartoœæ true.
	W momencie, gdy mo¿liwy jest ruch w danym kierunku zmienna osi¹ga wartoœæ false i nastêpuje zmiana kierunku poruszania gracza.*/
	bool	wantUpwards_;

	//! Atrybut œledzenia intencij gracza
	/*! Atrybut zapamiêtuj¹cy intencje gracza. Gdy gracz nie ma mo¿liwoœci skrêtu w dó³, atrybut posiada wartoœæ true.
	W momencie, gdy mo¿liwy jest ruch w danym kierunku zmienna osi¹ga wartoœæ false i nastêpuje zmiana kierunku poruszania gracza.*/
	bool	wantDownwards_;

	//! Atrybut œledzenia intencij gracza
	/*! Atrybut zapamiêtuj¹cy intencje gracza. Gdy gracz nie ma mo¿liwoœci skrêtu w lewo, atrybut posiada wartoœæ true.
	W momencie, gdy mo¿liwy jest ruch w danym kierunku zmienna osi¹ga wartoœæ false i nastêpuje zmiana kierunku poruszania gracza.*/
	bool	wantLeft_;

	//! Atrybut œledzenia intencij gracza
	/*! Atrybut zapamiêtuj¹cy intencje gracza. Gdy gracz nie ma mo¿liwoœci skrêtu w prawo, atrybut posiada wartoœæ true.
	W momencie, gdy mo¿liwy jest ruch w danym kierunku zmienna osi¹ga wartoœæ false i nastêpuje zmiana kierunku poruszania gracza.*/
	bool	wantRight_;


public:
	//! Konstruktor klasy .
	/*! Konstruktor odpowiedzialny za wpisanie wartoœci pocz¹tkowych gracza. 
	Ustalona zostaje pozycja, kszta³t i tekstura oraz prêdkoœc bazowa gracza.
	W konstruktorze wywo³ywany jest konstruktor klasy bazowej GameObject.
		\param window okno rozgrywki
		\param path œcie¿ka do wczytania tekstury gracza
		\param position pozycja pocz¹tkowa, na której pojawiæ ma siê postaæ gracza
		\param speed prêdkoœæ bazowa gracza 
		\sa GameObject*/
	Player(sf::RenderWindow& window, sf::String path, sf::Vector2f& position, float speed = 1.f);

	//! Destruktor klasy.
	/*! Destruktor klasy.*/
	~Player();

	//! Funkcja ustawiaj¹ca intencje gracza.
	/*! Funkcja odpowiedzialna za ustawienie atrybutu œledzenia intencji oraz mo¿liwoœci skrêtu gracza w górê.
		\param logic wartoœæ logiczna true lub false odpowiedzialna za przypisanie atrybutowi klasy wantUpwards_.
		\sa wantUpwards_*/
	void setWantUp(const bool& logic);

	//! Funkcja ustawiaj¹ca intencje gracza.
	/*! Funkcja odpowiedzialna za ustawienie atrybutu œledzenia intencji oraz mo¿liwoœci skrêtu gracza w dó³.
	\param logic wartoœæ logiczna true lub false odpowiedzialna za przypisanie atrybutowi klasy wantDownwards_.
	\sa wantDownwards_*/
	void setWantDown(const bool& logic);

	//! Funkcja ustawiaj¹ca intencje gracza
	/*! Funkcja odpowiedzialna za ustawienie atrybutu œledzenia intencji oraz mo¿liwoœci skrêtu gracza w lewo.
	\param logic wartoœæ logiczna true lub false odpowiedzialna za przypisanie atrybutowi klasy wantLeft_.
	\sa wantLeft_*/
	void setWantLeft(const bool& logic);

	//! Funkcja ustawiaj¹ca intencje gracza.
	/*! Funkcja odpowiedzialna za ustawienie atrybutu œledzenia intencji oraz mo¿liwoœci skrêtu gracza w prawo.
	\param logic wartoœæ logiczna true lub false odpowiedzialna za przypisanie atrybutowi klasy wantRight_.
	\sa wantRight_*/
	void setWantRight(const bool& logic);

	//! Funkcja ustawiaj¹ca moc gracza.
	/*! Funkcja odpowiedzialna za ustawienie atrybutu mocy gracza.
		\param power moc, któr¹ przypisuje siê graczowi
		\sa power_*/
	void setPower(const SpecialPower& power);
	
	//! Funkcja zwracaj¹ca intencje gracza
	/*! Funckja zwraca aktualny stan atrybutu wantUpwards_.
		\sa wantUpwards_*/
	bool getWantUp() const;

	//! Funkcja zwracaj¹ca intencje gracza
	/*! Funckja zwraca aktualny stan atrybutu wantDownwards_.
	\sa wantDownwards_*/
	bool getWantDown() const;

	//! Funkcja zwracaj¹ca intencje gracza
	/*! Funckja zwraca aktualny stan atrybutu wantLeft_.
	\sa wantLeft_*/
	bool getWantLeft() const;

	//! Funkcja zwracaj¹ca intencje gracza
	/*! Funckja zwraca aktualny stan atrybutu wantRight_.
	\sa wantRight_*/
	bool getWantRight() const;

	//!Funkcja zwracaj¹ca moc gracza
	/*! Funckaj zwraca aktualny stan atrybutu power_.
		\sa power_*/
	SpecialPower getPower() const;


	void getStates();


};

