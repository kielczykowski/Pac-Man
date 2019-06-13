#pragma once
#include "Map.h"
/*! \file GameObject.h
\brief Plik opisuj�cy klas� podstawow� gracza oraz przeciwnika

W pliku napisana jest klasa, kt�ra jest odpowiedzialna za stworzenie podstawowych funkcjonalno�ci oraz cech gracza i przeciwnik�w.
*/

//! Klasa Bazowa gracza i przeciwnik�w
/*! Klasa Bazowa, z kt�rej dziedziczone s� atrybuty oraz metody pozwalaj�ce na rozwini�cie rozgrywki oraz zapewnienie odpowiedniej logiki.*/
class GameObject
{
protected:
	//! Element cia�a 
	/*! Atrybut klasy, kt�ry bezpo�rednio zcala w sobie cechy wygl�du, pozcyji oraz reprezentuje dane cechy po narysowaniu w oknie gry.*/
	sf::Sprite	body_;

	//! Textura cia�a
	/*! Atrybut klasy, kt�ry odpowiedzialny jest za wczytanie grafiki cia�a gracza/przeciwnika. Przetrzymuje obraz oraz determinuje kszta�t elementu body_.*/
	sf::Texture	bodytexture_;

	//! Bazowa pr�dko�� 
	/*! Bazowa pr�dko��, kt�ra przypisywana jest na pocz�tku rozgrywki*/
	float	speed_;

	//! Pr�dko�c w kierunku poziomym
	/*! Pr�dko�c, z kt�r� aktualnie porusza si� element w kierunku poziomym podczas rozgrywki. Mo�e przyjmowa� warto�ci 0 lub speed_.
	\sa speed_*/
	float	speedx_;

	//! Pr�dko�c w kierunku pionowym
	/*! Pr�dko�c, z kt�r� aktualnie porusza si� element  w kierunku pionowym podczas rozgrywki. Mo�e przyjmowa� warto�ci 0 lub speed_.
	\sa speed_*/
	float	speedy_;



public:

	//! Konstruktor klasy 
	/*! Konstruktor klasy odpowiedzialny za przypisanie warto�ci atrybutom klasy.
		\param window okno gry
		\param path �cie�ka do wczytania tekstury gracza/przeciwnika
		\param position pocz�tkowa pozycja pojawienia na mapie
		\param speed warto�� pr�dko�ci bazowej elementu rozgrywki*/
	GameObject(sf::RenderWindow& window, sf::String path, sf::Vector2f& position, float speed);

	//! Destruktor klasy
	/*! Destruktor klasy.*/
	virtual ~GameObject();

	//! Funkcja zwracaj�ca cia�o elementu.
	/*! Funkcja zwracaj�ca cia�o elementu, w celu implementacji logiki. G��wne zastosowanie - sprawdzenie kolizji*/
	sf::Sprite getBody() const;

	//! Funkcja rysuj�ca element.
	/*! Funkcja odpowiedzialna za narysowanie elementu w oknie rogrywki.
		\param window okno rozgrywki, gdzie narysowany zostanie element.*/
	void draw(sf::RenderWindow& window) const;

	//! Funkcja zatrzymuj�ca ruch.
	/*! Funkcja odpowiedzialna za zerowanie pr�dko�ci elementu w kierunku poziomym oraz pionowym.
		Wywo�ywana podczas zderzenia z elementem.*/
	void stop();

	//! Funkcja poruszaj�ca graczem/przeciwnikiem.
	/*! Funkcja przesuwaj�ca element o warto�� parametru speedx_ oraz speed_y.
		\sa speedx_, speedy_*/
	void move();

	//! Funkcja ustalaj�ca pozycj�.
	/*! Funkcja odpowiedzialna za ustawienie pozycji elementu. Wywo�ywana po utracie �ycia przez gracza. W funckji uwzgl�dnione s� wymiary globalne okna oraz przesuni�cia planszy.
		\param x pozycja w kierunku poziomym
		\param y pozycha w kierunku pionowym*/
	void setPosition(float x, float y);

	sf::Vector2f getPosition();

	//! Funkcja okre�laj�ca kolizj�.
	/*! Funkcja sprawdzaj�ca czy po ruchu w danym kierunku jest mo�liwy. S�u�y do okre�lenia zderzenia z elementami Mapy.
		\param shape element mapy, po kt�rej porusza si� element
		\return zwraca warto�� true, gdy nast�puje kolizja, false w przypadku gdy nie ma kolizji.*/
	bool doesCollide(sf::RectangleShape& shape) const;
	
	//! Funkcja okre�laj�ca kolizj�.
	/*! Funkcja sprawdzaj�ca czy po ruchu w danym kierunku jest mo�liwy. S�u�y do okre�lenia zderzenia z punktami rozmieszczonymi na mapie (Point).
		\param shape element mapy, po kt�rej porusza si� element
		\return zwraca warto�� true, gdy nast�puje kolizja, false w przypadku gdy nie ma kolizji.
		\sa Point*/
	bool  doesCollide(sf::CircleShape& shape) const;

	//! Funkcja sprawdzaj�ca mo�liwo�� ruchu
	/*! Funkcja okre�laj�ca czy mo�liwe jest poruszenie si� elementu w prawo.
		\param objects wszystkie elementy mapy, kt�re potrzebne s� do okre�lenia czy gracz nie b�dzie kolidowa� z �adnym elementem mapy
		\return true - mo�liwy jest ruch w danym kierunku, false - brak mo�liwo�ci ruchu w danym kierunku
		\sa Map*/
	bool checkRight(std::vector<Map>& objects);

	//! Funkcja sprawdzaj�ca mo�liwo�� ruchu
	/*! Funkcja okre�laj�ca czy mo�liwe jest poruszenie si� elementu w lewo.
		\param objects wszystkie elementy mapy, kt�re potrzebne s� do okre�lenia czy gracz nie b�dzie kolidowa� z �adnym elementem mapy
		\return true - mo�liwy jest ruch w danym kierunku, false - brak mo�liwo�ci ruchu w danym kierunku
		\sa Map*/
	bool checkLeft(std::vector<Map>& objects);

	//! Funkcja sprawdzaj�ca mo�liwo�� ruchu
	/*! Funkcja okre�laj�ca czy mo�liwe jest poruszenie si� elementu w g�r�.
		\param objects wszystkie elementy mapy, kt�re potrzebne s� do okre�lenia czy gracz nie b�dzie kolidowa� z �adnym elementem mapy
		\return true - mo�liwy jest ruch w danym kierunku, false - brak mo�liwo�ci ruchu w danym kierunku
		\sa Map*/
	bool checkUp(std::vector<Map>& objects);

	//! Funkcja sprawdzaj�ca mo�liwo�� ruchu
	/*! Funkcja okre�laj�ca czy mo�liwe jest poruszenie si� elementu w g�r�.
		\param objects wszystkie elementy mapy, kt�re potrzebne s� do okre�lenia czy gracz nie b�dzie kolidowa� z �adnym elementem mapy
		\return true - mo�liwy jest ruch w danym kierunku, false - brak mo�liwo�ci ruchu w danym kierunku
		\sa Map*/
	bool checkDown(std::vector<Map>& objects);

	//!Funkcja ustawiaj�ca aktualn� pr�dko�� gracza.
	/*! Funkcja ustawiaj�ca pr�dko�� gracza w g�r� o warto�� atrybutu pr�dko�ci bazowej (speed_)
		/sa speed_*/
	void setmoveUp();

	//!Funkcja ustawiaj�ca aktualn� pr�dko�� gracza.
	/*! Funkcja ustawiaj�ca pr�dko�� gracza w d� o warto�� atrybutu pr�dko�ci bazowej (speed_)
	/sa speed_*/
	void setmoveDown();

	//!Funkcja ustawiaj�ca aktualn� pr�dko�� gracza.
	/*! Funkcja ustawiaj�ca pr�dko�� gracza w lewo o warto�� atrybutu pr�dko�ci bazowej (speed_)
	/sa speed_*/
	void setmoveLeft();

	//!Funkcja ustawiaj�ca aktualn� pr�dko�� gracza.
	/*! Funkcja ustawiaj�ca pr�dko�� gracza w prawo o warto�� atrybutu pr�dko�ci bazowej (speed_)
	/sa speed_*/
	void setmoveRight();

	//!Funkcja ustawiaj�ca pr�dko�� gracza/przeciwnika
	/*! Funkcja stworzona na potrzeb� zmiany pr�dko�ci bazowej elementu.
		\param speed nowa pr�dko�� bazowa elementu, kt�ra wpisana zostanie w argument speed_ klasy.
		\sa speed_*/
	void setSpeed(float speed);

	//! Funkcja zwracaj�ca aktualn� pr�dko��.
	/*! Funkcja zwracaj�ca aktualn� pr�dko�� gracza/przeciwnika w kierunku poziomym.*/
	float getXSpeed() const;

	//! Funkcja zwracaj�ca aktualn� pr�dko��.
	/*! Funkcja zwracaj�ca aktualn� pr�dko�� gracza/przeciwnika w kierunku pionowym.*/
	float getYSpeed() const;

};

