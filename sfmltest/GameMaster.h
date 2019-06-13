#pragma once
#include "GameLogic.h"

/*! \file GameMaster.h
\brief Plik opisuj�cy stany gry

W pliku napisana jest klasa odpowiedzialna za przydzielenie zada� programu, kt�re cz�ci aktualnie si� wykonuj�.
*/

//! Klasa Mstrza gry 
/*! Klasa determinuje jak powinna wygl�da� rozgrywka w danym momencie. Steruje, kt�re fragmenty kodu aktualnie si� wykonuj� i zawiera g��wn� p�tl� rozgrywki.*/

class GameMaster
{
private: 
	//not used ATM
	bool		exit;	// if game is paused and escape is clicked again -> loop exits
	bool		pause; // pausing game with escape -> escape sets pause to true
	sf::Clock	clock_;
	sf::Time	time_;
	//

	//! Atrybut punkt�w
	/*! Atrybt okre�la uzbieran� liczb� punkt�w przez gracza.*/
	int			score_;

	//! Atrybut �y� gracza
	/*! Atrybut okre�la ile �y� pozosta�o graczowi do zako�czenia rozgrywki. Zycia usuwane s� poprzez zetkni�cie si� gracza z przeciwnikiem.*/
	int			lifes_;

	//! Czcionka tekstu
	/*! Czcionka, kt�r� u�ywaj� teksty wy�wietlane w obr�bie okna */
	sf::Font	font_;

public:

	//! Konsturktor 
	GameMaster();

	//! Destruktor
	~GameMaster();

	//! Funkcja rozpoczynaj�ca.
	/*! Funckja wywo�ywana jest przed rozpocz�ciem rozgrywki wpisuj�c odpowiedni� stratow� liczb� punkt�w i �y�.*/
	void init();

	//! G��wna funckja gry
	/*! Funkcja odpowiedzialna jest za trwanie rozgrywki. Wszystkie zdarzenia wyst�puj� w tej funckji.
	Nast�puje rysowanie, wywo�anie logiki oraz aktualizacja stanu gry.
		\param window okno, w kt�rym odbywa si� rozgrywa
		\param event zdarzenie, kt�re nale�y obs�u�y� 
		\param hgh obiekt przechowuj�cy wynii rozgrywki(punkty oraz nickname)
		\param background t�o rozgrywki*/
	void main(sf::RenderWindow& window, sf::Event& event, Highscore& hgh, const sf::Sprite& background);

	//void spin(sf::RenderWindow& window, sf::Event& event);
	//updates score by value or addScore?
	
	//! Funkcja aktualizuj�ca punkty
	/*! Funkcja aktualizuje punkty po osi�gni�ciu punktu lub po zetkni�ciu z przeciwnikiem.
		\param value warto�� punkt�w dodawanych. mM�e by� ujemna lub dodatnia.*/
	void updateScore(int&& value = 100);

	void endSign(const std::string& str, sf::RenderWindow& window, sf::Font& font, GameLogic& logic);

	void endResult(sf::RenderWindow& window, sf::Event event, sf::Font* font, GameLogic& logic, Highscore& hgh);

	void drawMap(std::vector<Map>& map, sf::RenderWindow& window, Player& pl, std::vector<Enemy>& enemies);

	//! Funkcja usuwaj�ca �ycia
	/*! Funkcja odejmuje, zycie o okre�lon� wato��, gdy gracz zmierzy si� z przeciwnikiem bez supermocy.
		\param value  warto��, o kt�r� odejmowane s� �ycia*/
	void updateLifes(int&& value = -1);

	//! Funkcja �y�
	/*! Funkcja udost�pnia logice czy gracz �yje.
		\return true - liczba �yc wi�ksza od 0, false inny przypadek*/
	bool isDead() const;

	//! Funkcja rysuj�ca elementy rozgrywki
	/*! \param window okno rozgrywki*/
	void drawUpdates(sf::RenderWindow& window);


	//! Funkcja zwracaj�ca liczb� punkt�w
	/* \return liczba punkt�w uzyskanych w trakcie gry*/
	int getScore() const; //returns score after game2 

	bool getPause() const;
	bool getExit() const;

	//! Funkcja zwracaj�ca nick gracza
	/*! \return nick gracza*/
	sf::String getName() const; //returns nick after game


};

