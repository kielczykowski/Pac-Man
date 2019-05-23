#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject(sf::RenderWindow& window,sf::String path,sf::Vector2f& position)
{
	assert(bodytexture.loadFromFile(path));
	body.setTexture(bodytexture);
	body.setPosition(position);

}


GameObject::~GameObject()
{
}

void GameObject::draw(sf::RenderWindow& window) {
	window.draw(this->body);
}

sf::Sprite GameObject::getBody(){
	return body;
}
