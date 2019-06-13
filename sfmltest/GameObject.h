#pragma once
#include "Map.h"
/*! \file GameObject.h
\brief Plik opisuj¹cy klasê podstawow¹ gracza oraz przeciwnika

W pliku napisana jest klasa, która jest odpowiedzialna za stworzenie podstawowych funkcjonalnoœci oraz cech gracza i przeciwników.
*/

//! Klasa Bazowa gracza i przeciwników
/*! Klasa Bazowa, z której dziedziczone s¹ atrybuty oraz metody pozwalaj¹ce na rozwiniêcie rozgrywki oraz zapewnienie odpowiedniej logiki.*/
class GameObject
{
protected:
	//! Element cia³a 
	/*! Atrybut klasy, który bezpoœrednio zcala w sobie cechy wygl¹du, pozcyji oraz reprezentuje dane cechy po narysowaniu w oknie gry.*/
	sf::Sprite	body_;

	//! Textura cia³a
	/*! Atrybut klasy, który odpowiedzialny jest za wczytanie grafiki cia³a gracza/przeciwnika. Przetrzymuje obraz oraz determinuje kszta³t elementu body_.*/
	sf::Texture	bodytexture_;

	//! Bazowa prêdkoœæ 
	/*! Bazowa prêdkoœæ, która przypisywana jest na pocz¹tku rozgrywki*/
	float	speed_;

	//! Prêdkoœc w kierunku poziomym
	/*! Prêdkoœc, z któr¹ aktualnie porusza siê element w kierunku poziomym podczas rozgrywki. Mo¿e przyjmowaæ wartoœci 0 lub speed_.
	\sa speed_*/
	float	speedx_;

	//! Prêdkoœc w kierunku pionowym
	/*! Prêdkoœc, z któr¹ aktualnie porusza siê element  w kierunku pionowym podczas rozgrywki. Mo¿e przyjmowaæ wartoœci 0 lub speed_.
	\sa speed_*/
	float	speedy_;



public:

	//! Konstruktor klasy 
	/*! Konstruktor klasy odpowiedzialny za przypisanie wartoœci atrybutom klasy.
		\param window okno gry
		\param path œcie¿ka do wczytania tekstury gracza/przeciwnika
		\param position pocz¹tkowa pozycja pojawienia na mapie
		\param speed wartoœæ prêdkoœci bazowej elementu rozgrywki*/
	GameObject(sf::RenderWindow& window, sf::String path, sf::Vector2f& position, float speed);

	//! Destruktor klasy
	/*! Destruktor klasy.*/
	virtual ~GameObject();

	//! Funkcja zwracaj¹ca cia³o elementu.
	/*! Funkcja zwracaj¹ca cia³o elementu, w celu implementacji logiki. G³ówne zastosowanie - sprawdzenie kolizji*/
	sf::Sprite getBody() const;

	//! Funkcja rysuj¹ca element.
	/*! Funkcja odpowiedzialna za narysowanie elementu w oknie rogrywki.
		\param window okno rozgrywki, gdzie narysowany zostanie element.*/
	void draw(sf::RenderWindow& window) const;

	//! Funkcja zatrzymuj¹ca ruch.
	/*! Funkcja odpowiedzialna za zerowanie prêdkoœci elementu w kierunku poziomym oraz pionowym.
		Wywo³ywana podczas zderzenia z elementem.*/
	void stop();

	//! Funkcja poruszaj¹ca graczem/przeciwnikiem.
	/*! Funkcja przesuwaj¹ca element o wartoœæ parametru speedx_ oraz speed_y.
		\sa speedx_, speedy_*/
	void move();

	//! Funkcja ustalaj¹ca pozycjê.
	/*! Funkcja odpowiedzialna za ustawienie pozycji elementu. Wywo³ywana po utracie ¿ycia przez gracza. W funckji uwzglêdnione s¹ wymiary globalne okna oraz przesuniêcia planszy.
		\param x pozycja w kierunku poziomym
		\param y pozycha w kierunku pionowym*/
	void setPosition(float x, float y);

	sf::Vector2f getPosition();

	//! Funkcja okreœlaj¹ca kolizjê.
	/*! Funkcja sprawdzaj¹ca czy po ruchu w danym kierunku jest mo¿liwy. S³u¿y do okreœlenia zderzenia z elementami Mapy.
		\param shape element mapy, po której porusza siê element
		\return zwraca wartoœæ true, gdy nastêpuje kolizja, false w przypadku gdy nie ma kolizji.*/
	bool doesCollide(sf::RectangleShape& shape) const;
	
	//! Funkcja okreœlaj¹ca kolizjê.
	/*! Funkcja sprawdzaj¹ca czy po ruchu w danym kierunku jest mo¿liwy. S³u¿y do okreœlenia zderzenia z punktami rozmieszczonymi na mapie (Point).
		\param shape element mapy, po której porusza siê element
		\return zwraca wartoœæ true, gdy nastêpuje kolizja, false w przypadku gdy nie ma kolizji.
		\sa Point*/
	bool  doesCollide(sf::CircleShape& shape) const;

	//! Funkcja sprawdzaj¹ca mo¿liwoœæ ruchu
	/*! Funkcja okreœlaj¹ca czy mo¿liwe jest poruszenie siê elementu w prawo.
		\param objects wszystkie elementy mapy, które potrzebne s¹ do okreœlenia czy gracz nie bêdzie kolidowa³ z ¿adnym elementem mapy
		\return true - mo¿liwy jest ruch w danym kierunku, false - brak mo¿liwoœci ruchu w danym kierunku
		\sa Map*/
	bool checkRight(std::vector<Map>& objects);

	//! Funkcja sprawdzaj¹ca mo¿liwoœæ ruchu
	/*! Funkcja okreœlaj¹ca czy mo¿liwe jest poruszenie siê elementu w lewo.
		\param objects wszystkie elementy mapy, które potrzebne s¹ do okreœlenia czy gracz nie bêdzie kolidowa³ z ¿adnym elementem mapy
		\return true - mo¿liwy jest ruch w danym kierunku, false - brak mo¿liwoœci ruchu w danym kierunku
		\sa Map*/
	bool checkLeft(std::vector<Map>& objects);

	//! Funkcja sprawdzaj¹ca mo¿liwoœæ ruchu
	/*! Funkcja okreœlaj¹ca czy mo¿liwe jest poruszenie siê elementu w górê.
		\param objects wszystkie elementy mapy, które potrzebne s¹ do okreœlenia czy gracz nie bêdzie kolidowa³ z ¿adnym elementem mapy
		\return true - mo¿liwy jest ruch w danym kierunku, false - brak mo¿liwoœci ruchu w danym kierunku
		\sa Map*/
	bool checkUp(std::vector<Map>& objects);

	//! Funkcja sprawdzaj¹ca mo¿liwoœæ ruchu
	/*! Funkcja okreœlaj¹ca czy mo¿liwe jest poruszenie siê elementu w górê.
		\param objects wszystkie elementy mapy, które potrzebne s¹ do okreœlenia czy gracz nie bêdzie kolidowa³ z ¿adnym elementem mapy
		\return true - mo¿liwy jest ruch w danym kierunku, false - brak mo¿liwoœci ruchu w danym kierunku
		\sa Map*/
	bool checkDown(std::vector<Map>& objects);

	//!Funkcja ustawiaj¹ca aktualn¹ prêdkoœæ gracza.
	/*! Funkcja ustawiaj¹ca prêdkoœæ gracza w górê o wartoœæ atrybutu prêdkoœci bazowej (speed_)
		/sa speed_*/
	void setmoveUp();

	//!Funkcja ustawiaj¹ca aktualn¹ prêdkoœæ gracza.
	/*! Funkcja ustawiaj¹ca prêdkoœæ gracza w dó³ o wartoœæ atrybutu prêdkoœci bazowej (speed_)
	/sa speed_*/
	void setmoveDown();

	//!Funkcja ustawiaj¹ca aktualn¹ prêdkoœæ gracza.
	/*! Funkcja ustawiaj¹ca prêdkoœæ gracza w lewo o wartoœæ atrybutu prêdkoœci bazowej (speed_)
	/sa speed_*/
	void setmoveLeft();

	//!Funkcja ustawiaj¹ca aktualn¹ prêdkoœæ gracza.
	/*! Funkcja ustawiaj¹ca prêdkoœæ gracza w prawo o wartoœæ atrybutu prêdkoœci bazowej (speed_)
	/sa speed_*/
	void setmoveRight();

	//!Funkcja ustawiaj¹ca prêdkoœæ gracza/przeciwnika
	/*! Funkcja stworzona na potrzebê zmiany prêdkoœci bazowej elementu.
		\param speed nowa prêdkoœæ bazowa elementu, która wpisana zostanie w argument speed_ klasy.
		\sa speed_*/
	void setSpeed(float speed);

	//! Funkcja zwracaj¹ca aktualn¹ prêdkoœæ.
	/*! Funkcja zwracaj¹ca aktualn¹ prêdkoœæ gracza/przeciwnika w kierunku poziomym.*/
	float getXSpeed() const;

	//! Funkcja zwracaj¹ca aktualn¹ prêdkoœæ.
	/*! Funkcja zwracaj¹ca aktualn¹ prêdkoœæ gracza/przeciwnika w kierunku pionowym.*/
	float getYSpeed() const;

};

