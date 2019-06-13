#pragma once
#include "GameLogic.h"

/*! \file GameMaster.h
\brief Plik opisuj¹cy stany gry

W pliku napisana jest klasa odpowiedzialna za przydzielenie zadañ programu, które czêœci aktualnie siê wykonuj¹.
*/

//! Klasa Mstrza gry 
/*! Klasa determinuje jak powinna wygl¹daæ rozgrywka w danym momencie. Steruje, które fragmenty kodu aktualnie siê wykonuj¹ i zawiera g³ówn¹ pêtlê rozgrywki.*/

class GameMaster
{
private: 
	//not used ATM
	bool		exit;	// if game is paused and escape is clicked again -> loop exits
	bool		pause; // pausing game with escape -> escape sets pause to true
	sf::Clock	clock_;
	sf::Time	time_;
	//

	//! Atrybut punktów
	/*! Atrybt okreœla uzbieran¹ liczbê punktów przez gracza.*/
	int			score_;

	//! Atrybut ¿yæ gracza
	/*! Atrybut okreœla ile ¿yæ pozosta³o graczowi do zakoñczenia rozgrywki. Zycia usuwane s¹ poprzez zetkniêcie siê gracza z przeciwnikiem.*/
	int			lifes_;

	//! Czcionka tekstu
	/*! Czcionka, któr¹ u¿ywaj¹ teksty wyœwietlane w obrêbie okna */
	sf::Font	font_;

public:

	//! Konsturktor 
	GameMaster();

	//! Destruktor
	~GameMaster();

	//! Funkcja rozpoczynaj¹ca.
	/*! Funckja wywo³ywana jest przed rozpoczêciem rozgrywki wpisuj¹c odpowiedni¹ stratow¹ liczbê punktów i ¿yæ.*/
	void init();

	//! G³ówna funckja gry
	/*! Funkcja odpowiedzialna jest za trwanie rozgrywki. Wszystkie zdarzenia wystêpuj¹ w tej funckji.
	Nastêpuje rysowanie, wywo³anie logiki oraz aktualizacja stanu gry.
		\param window okno, w którym odbywa siê rozgrywa
		\param event zdarzenie, które nale¿y obs³u¿yæ 
		\param hgh obiekt przechowuj¹cy wynii rozgrywki(punkty oraz nickname)
		\param background t³o rozgrywki*/
	void main(sf::RenderWindow& window, sf::Event& event, Highscore& hgh, const sf::Sprite& background);

	//void spin(sf::RenderWindow& window, sf::Event& event);
	//updates score by value or addScore?
	
	//! Funkcja aktualizuj¹ca punkty
	/*! Funkcja aktualizuje punkty po osi¹gniêciu punktu lub po zetkniêciu z przeciwnikiem.
		\param value wartoœæ punktów dodawanych. mM¿e byæ ujemna lub dodatnia.*/
	void updateScore(int&& value = 100);

	void endSign(const std::string& str, sf::RenderWindow& window, sf::Font& font, GameLogic& logic);

	void endResult(sf::RenderWindow& window, sf::Event event, sf::Font* font, GameLogic& logic, Highscore& hgh);

	void drawMap(std::vector<Map>& map, sf::RenderWindow& window, Player& pl, std::vector<Enemy>& enemies);

	//! Funkcja usuwaj¹ca ¿ycia
	/*! Funkcja odejmuje, zycie o okreœlon¹ watoœæ, gdy gracz zmierzy siê z przeciwnikiem bez supermocy.
		\param value  wartoœæ, o któr¹ odejmowane s¹ ¿ycia*/
	void updateLifes(int&& value = -1);

	//! Funkcja ¿yæ
	/*! Funkcja udostêpnia logice czy gracz ¿yje.
		\return true - liczba ¿yc wiêksza od 0, false inny przypadek*/
	bool isDead() const;

	//! Funkcja rysuj¹ca elementy rozgrywki
	/*! \param window okno rozgrywki*/
	void drawUpdates(sf::RenderWindow& window);


	//! Funkcja zwracaj¹ca liczbê punktów
	/* \return liczba punktów uzyskanych w trakcie gry*/
	int getScore() const; //returns score after game2 

	bool getPause() const;
	bool getExit() const;

	//! Funkcja zwracaj¹ca nick gracza
	/*! \return nick gracza*/
	sf::String getName() const; //returns nick after game


};

