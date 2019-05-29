#include "stdafx.h"
#include "Player.h"


Player::Player(sf::RenderWindow& window, sf::String path, sf::Vector2f& position, float speed) : GameObject(window, path, position)
{
	std::cout << "PLEJER" << std::endl;
	this->speed_ = speed;
	this->speedx_ = 0;
	this->speedy_ = 0;
	wantDownwards_ = false;
	wantUpwards_ = false;
	wantRight_ = false;
	wantLeft_ = false;
}


Player::~Player()
{
}

void Player::update(sf::RenderWindow& window, sf::Event& event, std::vector<Map>& map){

	//checking possibilities for player to move
	bool canUp = checkUp(map);
	bool canDown = checkDown(map);
	bool canLeft = checkLeft(map);
	bool canRight = checkRight(map);
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::KeyPressed:
			switch (event.key.code) {
			case sf::Keyboard::Up:
				if (canUp){
					setmoveUp();
					wantUpwards_ = false;
					wantDownwards_ = false;
					wantRight_ = false;
					wantLeft_ = false;
				}
				else {
					wantUpwards_ = true;
					wantDownwards_ = false;
					wantRight_ = false;
					wantLeft_ = false;
				}
				break;

			case sf::Keyboard::Down:
				if (canDown) {
					setmoveDown();
					wantDownwards_ = false;
					wantUpwards_ = false;
					wantRight_ = false;
					wantLeft_ = false;
				}
				else {
					wantDownwards_ = true;
					wantUpwards_ = false;
					wantRight_ = false;
					wantLeft_ = false;
				}
				break;

			case sf::Keyboard::Left:
				if (canLeft) {
					setmoveLeft();
					wantLeft_ = false;
					wantRight_ = false;
					wantUpwards_ = false;
					wantDownwards_ = false;
				}
				else {
					wantLeft_ = true;
					wantRight_ = false;
					wantUpwards_ = false;
					wantDownwards_ = false;
				}
				break;

			case sf::Keyboard::Right:
				if (canRight) {
					setmoveRight();
					wantRight_ = false;
					wantLeft_ = false;
					wantUpwards_ = false;
					wantDownwards_ = false;
				}
				else {
					wantRight_ = true;
					wantLeft_ = false;
					wantUpwards_ = false;
					wantDownwards_ = false;
				}
				break;
				//case sf::Keyboard::Escape:
				//	window.close();
				//	break;
			}
		}

	}

	//moving 
	if (canUp && wantUpwards_) {
		setmoveUp();
		wantUpwards_ = false;
	}
	else if (canDown && wantDownwards_) {
		setmoveDown();
		wantDownwards_ = false;
	}
	else if (canLeft && wantLeft_) {
		setmoveLeft();
		wantLeft_ = false;
	}
	else if (canRight && wantRight_) {
		setmoveRight();
		wantRight_ = false;
	}
	else {}

	this->body_.move(speedx_, speedy_);
}

void Player::getStates() {
	std::cout << std::endl;
	std::cout << "stany zmiennych boolean" << std::endl;
	std::cout << "góra: " << wantUpwards_ << std::endl;
	std::cout << "dó³: " << wantDownwards_ << std::endl;
	std::cout << "lewo: " << wantLeft_ << std::endl;
	std::cout << "prawo: " << wantRight_ << std::endl;
}

void Player::setmoveDown() {
	speedx_ = 0;
	speedy_ = speed_;
}
void Player::setmoveUp() {
	speedx_ = 0;
	speedy_ = -speed_;
}

void Player::setmoveLeft() {
	speedx_ = -speed_;
	speedy_ = 0;
}

void Player::setmoveRight() {
	speedx_ = speed_;
	speedy_ = 0;
}

void Player::stop() {
	body_.move(-speedx_, -speedy_);
	speedx_ = 0;
	speedy_ = 0;
}

void Player::move(){
	body_.move(speedx_, speedy_);
}

void Player::setWantUp(const bool& logic){
	wantUpwards_ = logic;
}

void Player::setWantDown(const bool& logic){
	wantDownwards_ = logic;
}

void Player::setWantLeft(const bool& logic){
	wantLeft_ = logic;
}

void Player::setWantRight(const bool& logic){
	wantRight_ = logic;
}

bool Player::getWantUp() const{
	return wantUpwards_;
}
bool Player::getWantDown() const{
	return wantDownwards_;
}
bool Player::getWantLeft() const{
	return wantLeft_;
}
bool Player::getWantRight() const{
	return wantRight_;
}

float Player::getXSpeed() const{
	return speedx_;
}
float Player::getYSpeed() const{
	return speedy_;
}


bool Player::checkRight(std::vector<Map>& objects) {
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
bool Player::checkLeft(std::vector<Map>& objects) {
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

bool Player::checkUp(std::vector<Map>& objects) {
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

bool Player::checkDown(std::vector<Map>& objects) {
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

bool Player::doesCollide(sf::RectangleShape& shape) const {
	return body_.getGlobalBounds().intersects(shape.getGlobalBounds());
}

bool Player::doesCollide(sf::CircleShape& shape) const{
	return body_.getGlobalBounds().intersects(shape.getGlobalBounds());
}

void Player::setPosition(float x, float y){
	body_.setPosition(sf::Vector2f(x * MAP_PIXELS_SIZE + MAP_OFFSET_X, y * MAP_PIXELS_SIZE + MAP_OFFSET_Y));
}

void Player::checkMovementPossibility(sf::RectangleShape& shape){
	sf::FloatRect boundries = body_.getGlobalBounds();
	//boundries.
	//

}

