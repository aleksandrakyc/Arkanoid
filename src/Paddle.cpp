#include "pch.h"

Paddle::Paddle(float x, float y) : Block(x,y)
{
	initShape();
	this->shape.setPosition(x, y);

}

void Paddle::initShape()
{
	this->shape.setFillColor(sf::Color::Black);
	this->shape.setSize(sf::Vector2f(100.f, 20.f));

	this->shape.setOutlineThickness(-5);
	this->shape.setOutlineColor(sf::Color::White);
}

void Paddle::update()
{
	sf::FloatRect paddle = this->getPos();
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&(paddle.left>0))//check if not out of bounds
		this->shape.move(-speed, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&(paddle.left + paddle.width) < GlobalVars::width)
		this->shape.move(speed, 0.f);

}

