#pragma once

#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

class Player
{
private:
	float x, y;
	float width, height;
	float dx, dy;
	float speed;
	float currentFrame;
	int animationPosition;

	const float speedOfPerson = 0.1;

	int dir = 0;

	String file;
	Image playerImage;
	Texture texture;
	Sprite sprite;

public:
	Player(String file, int x, int y, float width, float height);
	~Player();

	void setSpeed(float speed);
	void setDir(float dir);

	int getDir();
	float getSpeed();
	Sprite getSprite();

	void animationsByInput(const float time);
	void updatePosition(const float time);
	
};