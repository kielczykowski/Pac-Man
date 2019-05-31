#pragma once
#include "Map.h"
class GameObject
{
protected:
	sf::Sprite	body_;
	sf::Texture	bodytexture_;

	float	speed_;
	float	speedx_;
	float	speedy_;



public:

	GameObject(sf::RenderWindow& window, sf::String path, sf::Vector2f& position, float speed);
	virtual ~GameObject();

	sf::Sprite getBody() const;

	//virtual void update(sf::RenderWindow& window, sf::Event& event, std::vector<Map>& map) = 0;
	void draw(sf::RenderWindow& window) const;

	void stop();
	void move();

	void setPosition(float x, float y);
	bool doesCollide(sf::RectangleShape& shape) const;
	//polymorphism not working
	bool  doesCollide(sf::CircleShape& shape) const;

	bool checkRight(std::vector<Map>& objects);
	bool checkLeft(std::vector<Map>& objects);
	bool checkUp(std::vector<Map>& objects);
	bool checkDown(std::vector<Map>& objects);

	void setmoveUp();
	void setmoveDown();
	void setmoveLeft();
	void setmoveRight();

	void setSpeed(float speed);

	float getXSpeed() const;
	float getYSpeed() const;

};

