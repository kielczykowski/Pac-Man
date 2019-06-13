#pragma once
#include "Highscore.h"

/*! \file GameLogic.h
\brief Plik opisuj�cy logik� gry

W pliku napisana jest klasa odpowiedzialna za obs�u�enie logiki rozgrywki.
*/

//! Klasa Logiki rozgrywki
/*! Klasa odpowiedzialna jest za decyzj�, jakie zdarzenia aktualnie maj� znaczenie, odlicza czasy trwania supermocy.*/
class GameLogic
{
private:
	//! Zmienna wa�no�ci mocy
	/*! Zmienna odpowiedzialna jest za obs�ugiwanie super mocy pacmana w momencie interakcji z przeciwnikiem.*/
	bool valid_power_;

	//! Atrybur Pauzy
	/*! Stwierdza czy aktualnie odbywa si� pauza w grze*/
	bool pause_;

	//! Atrybut Wyj�cia
	/*! Sprawdza czy nie nale�y opu�ci� g��wnej rozgrywki*/
	bool exit_;

	//! Atrybut zapisania
	/*! Stwierdza, w kt�rym momencie nale�y opu�ci� p�tl� zapisywania wynik�w*/
	bool save_score_;

	//! Zegar rozgrywki
	/*! Odmierza czas przez , kt�ry supermoc jest wa�na.*/
	sf::Clock clock_;

	//not used atm
	sf::Time time_;
	
public:

	//! Konstruktor klasy
	GameLogic();

	//!Destruktor klasy
	~GameLogic();

	//! Funkcja zwracaj�ca stan pauzy
	/*! Funkcja zwracaj�ca, czy aktualnie trwa przerwa.
		\return true - pauza, false - brak pauzy*/		
	bool getPause() const;

	//! Funkcja zwracaj�ca stan wyj�cia
	/*! Funkcja zwracaj�ca, czy aktualnie trzeba opu�ci� rozgrywk�
		\return true - wyj�cie, false - nie wychodzi�*/
	bool getExit() const;


	//! Funkcja zwracaj�ca stan zapisywania danych
	/*! Funkcja zwracaj�ca, czy nale�y opu�ci� p�tl� zapisywania wynik�w
		\param true - wyj�cie z p�tli, false - kr�� dalej*/
	bool getSaveScore() const;

	//! Funkcja zwracaj�ca stan dzia�ania mocy
	/*! Funkcja zwracaj�ca, czy moc gracza jest jeszcze aktywna
		\return true - moc jest aktywna, false - moc nie jest aktywna*/
	bool getValidPower() const;

	//! Funkcja ustawiaj�ca pauz�
	/*! \param logic true - pauza, false - brak pauzy
		\sa pause_*/
	void setPause(bool logic);

	//! Funkcja ustawiaj�ca wyj�cie
	/*! \param logic true - wyj�cie, false - nie wychodzi�*/
	void setExit(bool logic);

	//! Funkcja ustawiaj�ca wyj�cie z p�tli zapisywania danych
	/*! \param logic true - wyj�cie z p�tli, false - kr�� dalej*/
	void setSaveScore(bool logic);

	//! Funkcja ustawiaj�ca wa�no�c super mocy gracza
	/*! \param logic true - supermoc aktywna, false - supermoc nieaktywna*/
	void setValidPower(bool logic);

	//! Rozpocz�cie zliczania zegaru
	/*! Reset zegaru i rozpocz�cie odliczania*/
	void startClock();

	//! Funkcja pobiera odmierzony czas
	/*! Funkcja zwraca czas odmieczony przez zegar clock_
		\return zwraca czas, kt�ry min�� od poprzedniego wykonania instrukcji*/
	float getElapsedTime();


	//!Funckja logiki gracza
	/*! Funkcja odpowieda za obs�u�enie wszystkiech element�w gry zwi�zanych z graczem tj. sterowanie, kolizje, przyedzialanie punkt�w itp.
		\param window okno rozgrywki
		\param player obiekt gracza
		\param event obs�uga interakcji u�ytkownika
		\param map aktualna mapa rozgrywki*/
	void playerLogic(sf::RenderWindow& window, Player& player, sf::Event& event, std::vector<Map>& map);

	void enemyLogic(sf::RenderWindow& window, Player& player, std::vector<Enemy>& enemies, sf::Event& event, std::vector<Map>& map);

	//! Funkcja logiki przerwy
	/*! Funkcja odpowiedzialna jest za zastopowanie rozgrywki. W czasie pauzy, w obr�bie rozgrywi nie nast�puje zmiana.
	Obs�ugiwane jest kontynuacja oraz wyj�cie z gry
		\param window okno rozgrywki
		\param event obs�uga interakcji u�ytkownika*/
	void pausedGameLogic(sf::RenderWindow& window, sf::Event& event);

	//! Funkcja logiki pobierania danych
	/*! Po rozgrywce nast�puje pobieranie nicku oraz wyniku rozgrywki.
	Dana funkcja obs�uguje wpisywanie tekstu oraz przekazywanie danych do zak�adki Highscores.
		\param window okno rozgrywki
		\param event obs�uga interakcji u�ytkownika
		\param nick zmienna, kt�ra wy�wietla aktualny stan nicku wpisanego przez u�ytkownika*/
	void afterGameLogic(sf::RenderWindow& window, sf::Event& event, sf::String& nick);
};

