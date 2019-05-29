#pragma once
#include "Map.h"
class GameObject
{
protected:
	sf::Sprite	body_;
	sf::Texture	bodytexture_;

public:

	GameObject(sf::RenderWindow& window, sf::String path,sf::Vector2f& position);
	virtual ~GameObject();

	sf::Sprite getBody() const;

	virtual void update(sf::RenderWindow& window, sf::Event& event, std::vector<Map>& map) = 0;
	void draw(sf::RenderWindow& window) const;

	

};

