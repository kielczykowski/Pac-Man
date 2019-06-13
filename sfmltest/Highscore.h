#pragma once
#include "Point.h"

/*! \file Highscore.h
\brief Plik opisuj¹cy okno z najlepszymi wynikami

W pliku napisana jest klasa odpowiedzialna za wyœwietlenie, wczytanie i zapisanie najwy¿szych wyników, graczy koñcz¹cych rozgrywkê.
*/

//! Klasa najlepszych wyników
/*! Klasa odpowiedzialna za stworzenie okna, w którym wypisane zostan¹ najlepsze wyniki wraz z nickami graczy.*/
class Highscore
{
private:
	//! Wektor surowych danych
	/*! Atrybut, w którym dane przetrzymywane s¹ w postaci int oraz string.*/
	std::vector<ScoreData> data_;

	//! Wektor tekstów na ekran
	/*! Wektor przekonwertowanych danych na elementy, które mog¹ zostaæ wypisane w oknie gry.
		\sa data_*/
	std::vector<sf::Text> table_;

	//! Nazwa tabeli
	/*! Napis przetrzymuj¹cy nazwê tabeli oraz wyœwietlany na oknie.*/
	sf::Text table_name_;

	//! Czcionka okna
	/*! Czcionka, któr¹ wypisane s¹ wszystkie napisy w danym oknie*/
	sf::Font font_;
public:

	//! G³ówna funkcja klasy
	/*! W obrêbie tej funkcji wyœwietlane s¹ wszystkie elementy okna, analizowane s¹ zdarzenia od u¿ytkowanika, 
	które nastêpnie s¹ obs³u¿one w odpowiedni sposób.
		\param window okno, na którym rysowane s¹ elementy
		\param event obiekt, którym obs³uguje siê interakcjê u¿ytkownika
		\param background t³o okna*/
	void main(sf::RenderWindow& window, sf::Event& event, const sf::Sprite& background);

	//! Funkcja wczytuj¹ca dane z pliku
	/*! Funkcja wczytuje dane z pliku, wszystkie zapisane dotychczas najwy¿sze wyniki.*/
	void downloadHighscores();

	//! Funkcja zapisuj¹ca dane do pliku
	/*! Funkcja zapisuj¹ca dane do pliku.*/
	void saveHighscores();

	//!Funkcja rozpoczynaj¹ca
	/*! Funkcja, w której wszystkie zmienne klasy s¹ inicjalizowane, przed wyœwietleniem tabeli.
	U¿ywana w Konstruktorze oraz na pocz¹tku funkcji main.*/
	void initTable();

	//! Funkcja przesuwaj¹ca tabelê w górê.
	/*! Funkcja odpowiedzialna za poruszanie tabeli, w górê po odpowiedniej interakcji u¿ytkownika.*/
	void moveTableUp();

	//! Funkcja przesuwaj¹ca tabelê w dó³.
	/*! Funkcja odpowiedzialna za poruszanie tabeli, w dó³ po odpowiedniej interakcji u¿ytkownika.*/
	void moveTableDown();

	//! Funkcja dodaj¹ca nowy rekord
	/*! Funckja, która dodaje do aktualnego wektora danych nowy element.
		\param highscore nowy element wektora data_
		\sa data_*/
	void addHighscores(ScoreData& highscore);

	//! Funkcja dodaj¹ca nowy rekord
	/*! Funckja, która dodaje do aktualnego wektora danych nowy element.
		\param name nick u¿ytkownika
		\param points liczba punktów, które uzyska³ u¿ytkownik
		\sa data_*/
	void addHighscores(const std::string& name, int points);

	void printHighscores();

	//! Funkcja obs³uguj¹ca interackjê
	/*! Funckja odpowiada za obs³uzênie interakcji u¿ytkownika tj. u¿ycie odpowiednich klawiszy lub myszki
		\param window okno, w obszarze, którego dziej¹ siê zdarzenia*/
	void update(sf::RenderWindow& window); //event handling

	//!Konstruktor klasy
	Highscore();

	//!Destruktor klasy
	~Highscore();
};

