#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject(sf::RenderWindow& window, sf::String path, sf::Vector2f& position, float speed)
{
	assert(bodytexture_.loadFromFile(path));
	body_.setTexture(bodytexture_);
	setPosition(position.x, position.y);
	this->speed_ = speed;
	this->speedx_ = 0;
	this->speedy_ = 0;
}


GameObject::~GameObject()
{
}

void GameObject::draw(sf::RenderWindow& window) const{
	window.draw(this->body_);
}

sf::Sprite GameObject::getBody() const {
	return body_;
}
//


bool GameObject::doesCollide(sf::CircleShape& shape) const{
	return body_.getGlobalBounds().intersects(shape.getGlobalBounds());
}


bool GameObject::doesCollide(sf::RectangleShape& shape) const {
	return body_.getGlobalBounds().intersects(shape.getGlobalBounds());
}
void GameObject::setPosition(float x, float y){
	body_.setPosition(sf::Vector2f(x * MAP_PIXELS_SIZE + MAP_OFFSET_X, y * MAP_PIXELS_SIZE + MAP_OFFSET_Y));
}


void GameObject::stop() {
	body_.move(-speedx_, -speedy_);
	speedx_ = 0;
	speedy_ = 0;
}

void GameObject::move(){
	body_.move(speedx_, speedy_);
}

bool GameObject::checkRight(std::vector<Map>& objects) {
	body_.move(speed_, 0);
	for (auto& object : objects) {
		if (body_.getGlobalBounds().intersects(object.getShape().getGlobalBounds())){
			body_.move(-speed_, 0);
			return false;
		}
	}
	body_.move(-speed_, 0);
	return true;
}
bool GameObject::checkLeft(std::vector<Map>& objects) {
	body_.move(-speed_, 0);
	for (auto& object : objects) {
		if (body_.getGlobalBounds().intersects(object.getShape().getGlobalBounds())){
			body_.move(speed_, 0);
			return false;
		}
	}
	body_.move(speed_, 0);
	return true;
}

bool GameObject::checkUp(std::vector<Map>& objects) {
	body_.move(0, -speed_);
	for (auto& object : objects) {
		if (body_.getGlobalBounds().intersects(object.getShape().getGlobalBounds())){
			body_.move(0, speed_);
			return false;
		}
	}
	body_.move(0, speed_);
	return true;
}

bool GameObject::checkDown(std::vector<Map>& objects) {
	body_.move(0, speed_);
	for (auto& object : objects) {
		if (body_.getGlobalBounds().intersects(object.getShape().getGlobalBounds())){
			body_.move(0, -speed_);
			return false;
		}
	}
	body_.move(0, -speed_);
	return true;
}

void GameObject::setmoveDown() {
	speedx_ = 0;
	speedy_ = speed_;
}
void GameObject::setmoveUp() {
	speedx_ = 0;
	speedy_ = -speed_;
}

void GameObject::setmoveLeft() {
	speedx_ = -speed_;
	speedy_ = 0;
}

void GameObject::setmoveRight() {
	speedx_ = speed_;
	speedy_ = 0;
}


void GameObject::setSpeed(float speed){
	speed_ = speed;
}




float GameObject::getXSpeed() const{
	return speedx_;
}
float GameObject::getYSpeed() const{
	return speedy_;
}
