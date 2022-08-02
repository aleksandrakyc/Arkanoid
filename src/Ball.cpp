#include "pch.h"
#include <iostream>


void Ball::initShape()
{
	this->shape.setFillColor(sf::Color::White);
	this->shape.setRadius(5.f);
}

void Ball::setAngle(float angle)
{
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

	//dziwne zachowanie - 595 690
	this->shape.setPosition(595, 690);
	this->speed = 3;
	this->velocity.x = 0;
	this->velocity.y = 0;
}

sf::Vector2f Ball::getVelo()
{
	return velocity;
}

bool Ball::checkCollision(const Paddle& paddle)
{
	sf::FloatRect ballPos = this->shape.getGlobalBounds();
	sf::FloatRect paddlePos = paddle.getPos();

	if (paddlePos.intersects(ballPos)) {

		float distanceFromCenter = ballPos.left - paddlePos.left;

		float angle = 180-distanceFromCenter*1.8; 
		
		setAngle(angle);

		return true;
	}



	return false;
}

bool Ball::checkCollision(const Brick& brick)
{
	//WIP!!!
	auto ballRect = this->shape.getGlobalBounds();
	auto brickRect = brick.getPos();

	
	if (ballRect.intersects(brickRect))
	{
		
		if (ballRect.left < brickRect.left || ballRect.left+ballRect.width> brickRect.left + brickRect.width) //dziala tylko ta strona po ktorej sprawdza, teraz dziala dobrze bok tylko trzeba dol obsluzyc
		{
			//na sile fest
			if (velocity.x != 0) {
				velocity.x *= -1;
			}
			else {
				velocity.y *= -1;
			}
		}
		else if (ballRect.top < brickRect.top || ballRect.top + ballRect.height> brickRect.top + brickRect.height){

			velocity.y *= -1;

		}
		else { //unnecessary?
			velocity.x *= -1;
			velocity.y *= -1;
		}
		return true;
		
	}

	
	//we already know they intersect - now we have to check whether the top/bottom or left/right coords are met
	//it just goes into the first if always

	//if (brickRect.left <= ballRect.left && ballRect.left<= (brickRect.left + brickRect.width)
	//	|| brickRect.left <= ballRect.left+ballRect.width && ballRect.left + ballRect.width <= (brickRect.left + brickRect.width)) {
	//	if (ballRect.intersects(brickRect)) {
	//		velocity.y = -velocity.y;

	//		return true;
	//	}
	//}
	//if (brickRect.top <= ballRect.top && ballRect.top <= (brickRect.top + brickRect.height)
	//	|| brickRect.top <= ballRect.top + ballRect.height && ballRect.top + ballRect.height <= (brickRect.top + brickRect.height)) {
	//	if (ballRect.intersects(brickRect)) {
	//		velocity.x = -velocity.x;
	//		//clumsy

	//		return true;
	//	}

	//}

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

			this->velocity.y = this->speed;
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