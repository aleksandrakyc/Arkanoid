#pragma once

class Button
	: public Block
{
	bool mouseIn(sf::Vector2i mouse);

	void initShape() override;

public:

	Button(float x, float y);

	bool update(sf::Event e, sf::RenderWindow* window);

};