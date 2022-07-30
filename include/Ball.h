#pragma once
#include <numbers>
class Ball
	
{
	sf::CircleShape shape;
	float speed;
	sf::Vector2f velocity;

	void initShape();
	void setAngle(float angle);

public:

	Ball(float x, float y);
	Ball();
	
	sf::Vector2f getVelo();

	bool checkCollision(const Paddle& paddle); 
	bool checkCollision(const Brick& brick);//maybe i can make it work for both
	bool checkFall();
	void update();
	void move();
	bool clickStart(sf::Event e);
	void render(sf::RenderTarget* target);
};