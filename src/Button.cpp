#include "pch.h"



bool Button::mouseIn(sf::Vector2i mouse)
{
	sf::Vector2f mouseFloat(mouse);

	if (this->shape.getGlobalBounds().contains(mouseFloat)){
		return true;
	}
	return false;

}

Button::Button(float x, float y) : Block(x,y)
{
	initShape();
	this->shape.setPosition(x, y);
}


bool Button::update(sf::Event e, sf::RenderWindow* window)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
	
	if (e.type == sf::Event::MouseButtonPressed) {

		if (mouseIn(mousePosition)) {
			return true;
		}
	}
	return false;
}

void Button::initShape()
{
	this->shape.setFillColor(sf::Color::Black);
	this->shape.setSize(sf::Vector2f(300.f, 100.f));

	this->shape.setOutlineThickness(-5);
	this->shape.setOutlineColor(sf::Color::White);
}
