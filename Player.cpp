#include "Player.h"
#include <iostream>

Player::Player(String file, int x, int y, float width, float height)
	:x(0), y(0), width(0), height(0), dx(0), dy(0), speed(0), currentFrame(0), animationPosition(0)
{
	this->file = file;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

	if(playerImage.loadFromFile("images/" + this->file)) { std::cout << "file was successful loaded!" << std::endl; }
	else { std::cout << "file was unsuccessful loaded!!!" << std::endl; }
	playerImage.createMaskFromColor(Color(41, 33, 59));
	playerImage.createMaskFromColor(Color(41, 33, 59));

	texture.loadFromImage(playerImage);

	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(height, width, height, width));
}

Player::~Player() {

}

void Player::updatePosition(const float time) {
	switch (dir) {
	case 0: dx = speed;	dy = 0;  break;
	case 1: dx = -speed; dy = 0; break;
	case 2: dx = 0; dy = speed;	 break;
	case 3: dx = 0; dy = -speed; break;
	}

	x += dx * time;
	y += dy * time;

	speed = 0;
	sprite.setPosition(x, y);
}

void Player::animationsByInput(const float time) {
	if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
		this->setDir(1); this->setSpeed(speedOfPerson);
		currentFrame += 0.005*time;
		if (currentFrame > 3) currentFrame -= 3;
		this->sprite.setTextureRect(IntRect(96 * int(currentFrame), 96, 96, 96));
	}

	if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
		this->setDir(0); this->setSpeed(speedOfPerson);
		currentFrame += 0.005*time;
		if (currentFrame > 3) currentFrame -= 3;
		this->sprite.setTextureRect(IntRect(96 * int(currentFrame), 192, 96, 96));
	}

	if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
		this->setDir(3); this->setSpeed(speedOfPerson);
		currentFrame += 0.005*time;
		if (currentFrame > 3) currentFrame -= 3;
		this->sprite.setTextureRect(IntRect(96 * int(currentFrame), 288, 96, 96));

	}

	if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) {
		this->setDir(2); this->setSpeed(speedOfPerson);
		currentFrame += 0.005*time;
		if (currentFrame > 3) currentFrame -= 3;
		this->sprite.setTextureRect(IntRect(96 * int(currentFrame), 0, 96, 96));

	}
}

void Player::setSpeed(float speed) {
	this->speed = speed;
}

void Player::setDir(float dir) {
	this->dir = dir;
}

int Player::getDir() {
	return this->dir;
}

float Player::getSpeed() {
	return this->speed;
}

Sprite Player::getSprite() {
	return this->sprite;
}