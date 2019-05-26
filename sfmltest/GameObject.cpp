#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject(sf::RenderWindow& window, sf::String path, sf::Vector2f& position)
{
	assert(bodytexture_.loadFromFile(path));
	body_.setTexture(bodytexture_);
	body_.setPosition(position);

}


GameObject::~GameObject()
{
}

void GameObject::draw(sf::RenderWindow& window) {
	window.draw(this->body_);
}

sf::Sprite GameObject::getBody(){
	return body_;
}
