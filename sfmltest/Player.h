#pragma once
#include "GameObject.h"
 
class Player : public GameObject
{
private: 
	SpecialPower power_;

	bool	wantUpwards_;
	bool	wantDownwards_;
	bool	wantLeft_;
	bool	wantRight_;


public:
	Player(sf::RenderWindow& window, sf::String path, sf::Vector2f& position, float speed = 1.f);
	~Player();

	//void update(sf::RenderWindow& window, sf::Event& event, std::vector<Map>& map) override;

	//void checkMovementPossibility(sf::RectangleShape& shape);
	
	void setWantUp(const bool& logic);
	void setWantDown(const bool& logic);
	void setWantLeft(const bool& logic);
	void setWantRight(const bool& logic);
	void setPower(const SpecialPower& power);

	bool getWantUp() const;
	bool getWantDown() const;
	bool getWantLeft() const;
	bool getWantRight() const;
	SpecialPower getPower() const;


	void getStates();


};

