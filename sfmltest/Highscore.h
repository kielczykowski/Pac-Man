#pragma once
#include "Point.h"

/*! \file Highscore.h
\brief Plik opisuj�cy okno z najlepszymi wynikami

W pliku napisana jest klasa odpowiedzialna za wy�wietlenie, wczytanie i zapisanie najwy�szych wynik�w, graczy ko�cz�cych rozgrywk�.
*/

//! Klasa najlepszych wynik�w
/*! Klasa odpowiedzialna za stworzenie okna, w kt�rym wypisane zostan� najlepsze wyniki wraz z nickami graczy.*/
class Highscore
{
private:
	//! Wektor surowych danych
	/*! Atrybut, w kt�rym dane przetrzymywane s� w postaci int oraz string.*/
	std::vector<ScoreData> data_;

	//! Wektor tekst�w na ekran
	/*! Wektor przekonwertowanych danych na elementy, kt�re mog� zosta� wypisane w oknie gry.
		\sa data_*/
	std::vector<sf::Text> table_;

	//! Nazwa tabeli
	/*! Napis przetrzymuj�cy nazw� tabeli oraz wy�wietlany na oknie.*/
	sf::Text table_name_;

	//! Czcionka okna
	/*! Czcionka, kt�r� wypisane s� wszystkie napisy w danym oknie*/
	sf::Font font_;
public:

	//! G��wna funkcja klasy
	/*! W obr�bie tej funkcji wy�wietlane s� wszystkie elementy okna, analizowane s� zdarzenia od u�ytkowanika, 
	kt�re nast�pnie s� obs�u�one w odpowiedni spos�b.
		\param window okno, na kt�rym rysowane s� elementy
		\param event obiekt, kt�rym obs�uguje si� interakcj� u�ytkownika
		\param background t�o okna*/
	void main(sf::RenderWindow& window, sf::Event& event, const sf::Sprite& background);

	//! Funkcja wczytuj�ca dane z pliku
	/*! Funkcja wczytuje dane z pliku, wszystkie zapisane dotychczas najwy�sze wyniki.*/
	void downloadHighscores();

	//! Funkcja zapisuj�ca dane do pliku
	/*! Funkcja zapisuj�ca dane do pliku.*/
	void saveHighscores();

	//!Funkcja rozpoczynaj�ca
	/*! Funkcja, w kt�rej wszystkie zmienne klasy s� inicjalizowane, przed wy�wietleniem tabeli.
	U�ywana w Konstruktorze oraz na pocz�tku funkcji main.*/
	void initTable();

	//! Funkcja przesuwaj�ca tabel� w g�r�.
	/*! Funkcja odpowiedzialna za poruszanie tabeli, w g�r� po odpowiedniej interakcji u�ytkownika.*/
	void moveTableUp();

	//! Funkcja przesuwaj�ca tabel� w d�.
	/*! Funkcja odpowiedzialna za poruszanie tabeli, w d� po odpowiedniej interakcji u�ytkownika.*/
	void moveTableDown();

	//! Funkcja dodaj�ca nowy rekord
	/*! Funckja, kt�ra dodaje do aktualnego wektora danych nowy element.
		\param highscore nowy element wektora data_
		\sa data_*/
	void addHighscores(ScoreData& highscore);

	//! Funkcja dodaj�ca nowy rekord
	/*! Funckja, kt�ra dodaje do aktualnego wektora danych nowy element.
		\param name nick u�ytkownika
		\param points liczba punkt�w, kt�re uzyska� u�ytkownik
		\sa data_*/
	void addHighscores(const std::string& name, int points);

	void printHighscores();

	//! Funkcja obs�uguj�ca interackj�
	/*! Funckja odpowiada za obs�uz�nie interakcji u�ytkownika tj. u�ycie odpowiednich klawiszy lub myszki
		\param window okno, w obszarze, kt�rego dziej� si� zdarzenia*/
	void update(sf::RenderWindow& window); //event handling

	//!Konstruktor klasy
	Highscore();

	//!Destruktor klasy
	~Highscore();
};

