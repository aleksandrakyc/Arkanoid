#include "pch.h"

void Brick::initShape()
{
	this->shape.setFillColor(sf::Color::Black);
	this->shape.setSize(sf::Vector2f(100.f, 40.f));

	this->shape.setOutlineThickness(-5);
	this->shape.setOutlineColor(sf::Color::White);

}

Brick::Brick(float x, float y)
{
	initShape();
	this->shape.setPosition(x, y);
}
