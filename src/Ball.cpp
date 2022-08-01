#include "pch.h"
#include <iostream>


void Ball::initShape()
{
	this->shape.setFillColor(sf::Color::White);
	this->shape.setRadius(10.f);

}

void Ball::setAngle(float angle)
{
	//takes angle between 0-180 degrees, undebatable
	velocity.x = speed * std::cos(angle * std::numbers::pi / 180);
	velocity.y = -speed * std::sin(angle * std::numbers::pi / 180);
}

Ball::Ball(float x, float y)
{
	initShape();
	this->shape.setPosition(x,y);
}

Ball::Ball()
{
	initShape();

	this->shape.setPosition(590, 680);
	this->speed = 5;
	this->velocity.x = 0;
	this->velocity.y = 0;
}

sf::Vector2f Ball::getVelo()
{
	return velocity;
}

bool Ball::checkCollision(const Paddle& paddle)
{
	//this needs to be revised

	sf::Vector2f pos = shape.getPosition();
	//offset to get the lowest point
	
	pos.y += 20;
	int radius = shape.getRadius();

	sf::FloatRect paddlePos = paddle.getPos();

	if (paddlePos.contains(pos)) {

		float distanceFromCenter = pos.x - paddlePos.left;
		//std::cout << distanceFromCenter << std::endl;
		float angle = 180-distanceFromCenter*1.8; //0-180 tak jakby na odwrot
		
		//std::cout << angle << std::endl;

		setAngle(angle);

		return true;
	}



	return false;
}

bool Ball::checkCollision(const Brick& brick)
{
	//problem when hitting block from the left side
	sf::FloatRect ballPos = this->shape.getGlobalBounds();

	sf::Vector2f ballVec = shape.getPosition();
	int radius = shape.getRadius();

	sf::FloatRect brickPos = brick.getPos();

	if (brickPos.left<=ballVec.x&& ballVec.x<=(brickPos.left+brickPos.width)) {

		if (brickPos.top <= ballVec.y && ballVec.y <= (brickPos.top + brickPos.height)) {

			velocity.y = -velocity.y;

			return true;
			
		}

	}
	if (brickPos.top <= ballVec.y && ballVec.y <= (brickPos.top + brickPos.height)) {

		if (brickPos.left <= ballVec.x && ballVec.x <= (brickPos.left + brickPos.width)) {

			velocity.x = -velocity.x;
			//clumsy

			return true;
		}

	}

	return false;
}

bool Ball::checkFall()
{
	if (this->shape.getPosition().y > GlobalVars::height) {
		return true;
	}
	return false;
}

void Ball::update()
{
	
	sf::Vector2f pos = shape.getPosition();
	int radius = shape.getRadius();
	if (pos.x - radius <= 0.f)
		velocity.x = -velocity.x;
	if (pos.x + 2*radius >= GlobalVars::width)
		velocity.x = -velocity.x;
	if (pos.y <= 0.f)
		velocity.y = -velocity.y;

}

void Ball::move()
{
	shape.move(velocity);
}

bool Ball::clickStart(sf::Event e)
{

	if (velocity.x == 0 && velocity.y == 0) {

		if (e.type == sf::Event::MouseButtonPressed) {
			this->velocity.y = -5;
			return true;
		}

		return false;
	}
	return true;
}

void Ball::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}