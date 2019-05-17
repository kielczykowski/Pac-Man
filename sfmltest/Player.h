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

	void checkMovementPossibility(sf::RectangleShape& shape);
	bool checkRight(std::vector<Map>& objects);
	bool checkLeft(std::vector<Map>& objects);
	bool checkUp(std::vector<Map>& objects);
	bool checkDown(std::vector<Map>& objects);

	void getStates();

	void stop();
	bool doesCollide(sf::RectangleShape& shape);

};

