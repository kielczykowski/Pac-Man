#pragma once
#include "GameObject.h"
 
class Player : public GameObject
{
private: 
	float speed;
	float speedx;
	float speedy;

	bool wantUpwards;
	bool wantDownwards;
	bool wantLeft;
	bool wantRight;

public:
	Player(sf::RenderWindow& window, sf::String path, sf::Vector2f& position, float speed = 1.f);
	~Player();
	void update(sf::RenderWindow& window, sf::Event& event, std::vector<Map>& map) override;

	void setmoveUp();
	void setmoveDown();
	void setmoveLeft();
	void setmoveRight();

	void setWantUp(const bool& logic);
	void setWantDown(const bool& logic);
	void setWantLeft(const bool& logic);
	void setWantRight( const bool& logic);

	bool getWantUp();
	bool getWantDown();
	bool getWantLeft();
	bool getWantRight();

	float getXSpeed();
	float getYSpeed();

	void checkMovementPossibility(sf::RectangleShape& shape);
	bool checkRight(std::vector<Map>& objects);
	bool checkLeft(std::vector<Map>& objects);
	bool checkUp(std::vector<Map>& objects);
	bool checkDown(std::vector<Map>& objects);

	void getStates();

	void stop();
	void move();
	void setPosition(float x, float y);
	bool doesCollide(sf::RectangleShape& shape);
	bool doesCollide(sf::CircleShape& shape);

};

