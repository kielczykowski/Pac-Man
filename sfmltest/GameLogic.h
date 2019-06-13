#pragma once
#include "Highscore.h"

/*! \file GameLogic.h
\brief Plik opisuj¹cy logikê gry

W pliku napisana jest klasa odpowiedzialna za obs³u¿enie logiki rozgrywki.
*/

//! Klasa Logiki rozgrywki
/*! Klasa odpowiedzialna jest za decyzjê, jakie zdarzenia aktualnie maj¹ znaczenie, odlicza czasy trwania supermocy.*/
class GameLogic
{
private:
	//! Zmienna wa¿noœci mocy
	/*! Zmienna odpowiedzialna jest za obs³ugiwanie super mocy pacmana w momencie interakcji z przeciwnikiem.*/
	bool valid_power_;

	//! Atrybur Pauzy
	/*! Stwierdza czy aktualnie odbywa siê pauza w grze*/
	bool pause_;

	//! Atrybut Wyjœcia
	/*! Sprawdza czy nie nale¿y opuœciæ g³ównej rozgrywki*/
	bool exit_;

	//! Atrybut zapisania
	/*! Stwierdza, w którym momencie nale¿y opuœciæ pêtlê zapisywania wyników*/
	bool save_score_;

	//! Zegar rozgrywki
	/*! Odmierza czas przez , który supermoc jest wa¿na.*/
	sf::Clock clock_;

	//not used atm
	sf::Time time_;
	
public:

	//! Konstruktor klasy
	GameLogic();

	//!Destruktor klasy
	~GameLogic();

	//! Funkcja zwracaj¹ca stan pauzy
	/*! Funkcja zwracaj¹ca, czy aktualnie trwa przerwa.
		\return true - pauza, false - brak pauzy*/		
	bool getPause() const;

	//! Funkcja zwracaj¹ca stan wyjœcia
	/*! Funkcja zwracaj¹ca, czy aktualnie trzeba opuœciæ rozgrywkê
		\return true - wyjœcie, false - nie wychodziæ*/
	bool getExit() const;


	//! Funkcja zwracaj¹ca stan zapisywania danych
	/*! Funkcja zwracaj¹ca, czy nale¿y opuœciæ pêtlê zapisywania wyników
		\param true - wyjœcie z pêtli, false - krêæ dalej*/
	bool getSaveScore() const;

	//! Funkcja zwracaj¹ca stan dzia³ania mocy
	/*! Funkcja zwracaj¹ca, czy moc gracza jest jeszcze aktywna
		\return true - moc jest aktywna, false - moc nie jest aktywna*/
	bool getValidPower() const;

	//! Funkcja ustawiaj¹ca pauzê
	/*! \param logic true - pauza, false - brak pauzy
		\sa pause_*/
	void setPause(bool logic);

	//! Funkcja ustawiaj¹ca wyjœcie
	/*! \param logic true - wyjœcie, false - nie wychodziæ*/
	void setExit(bool logic);

	//! Funkcja ustawiaj¹ca wyjœcie z pêtli zapisywania danych
	/*! \param logic true - wyjœcie z pêtli, false - krêæ dalej*/
	void setSaveScore(bool logic);

	//! Funkcja ustawiaj¹ca wa¿noœc super mocy gracza
	/*! \param logic true - supermoc aktywna, false - supermoc nieaktywna*/
	void setValidPower(bool logic);

	//! Rozpoczêcie zliczania zegaru
	/*! Reset zegaru i rozpoczêcie odliczania*/
	void startClock();

	//! Funkcja pobiera odmierzony czas
	/*! Funkcja zwraca czas odmieczony przez zegar clock_
		\return zwraca czas, który min¹³ od poprzedniego wykonania instrukcji*/
	float getElapsedTime();


	//!Funckja logiki gracza
	/*! Funkcja odpowieda za obs³u¿enie wszystkiech elementów gry zwi¹zanych z graczem tj. sterowanie, kolizje, przyedzialanie punktów itp.
		\param window okno rozgrywki
		\param player obiekt gracza
		\param event obs³uga interakcji u¿ytkownika
		\param map aktualna mapa rozgrywki*/
	void playerLogic(sf::RenderWindow& window, Player& player, sf::Event& event, std::vector<Map>& map);

	void enemyLogic(sf::RenderWindow& window, Player& player, std::vector<Enemy>& enemies, sf::Event& event, std::vector<Map>& map);

	//! Funkcja logiki przerwy
	/*! Funkcja odpowiedzialna jest za zastopowanie rozgrywki. W czasie pauzy, w obrêbie rozgrywi nie nastêpuje zmiana.
	Obs³ugiwane jest kontynuacja oraz wyjœcie z gry
		\param window okno rozgrywki
		\param event obs³uga interakcji u¿ytkownika*/
	void pausedGameLogic(sf::RenderWindow& window, sf::Event& event);

	//! Funkcja logiki pobierania danych
	/*! Po rozgrywce nastêpuje pobieranie nicku oraz wyniku rozgrywki.
	Dana funkcja obs³uguje wpisywanie tekstu oraz przekazywanie danych do zak³adki Highscores.
		\param window okno rozgrywki
		\param event obs³uga interakcji u¿ytkownika
		\param nick zmienna, która wyœwietla aktualny stan nicku wpisanego przez u¿ytkownika*/
	void afterGameLogic(sf::RenderWindow& window, sf::Event& event, sf::String& nick);
};

