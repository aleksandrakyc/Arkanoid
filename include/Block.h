#pragma once

class Block
{
protected:

	sf::RectangleShape shape;
	virtual void initShape() = 0;

public:
	sf::FloatRect getPos() const { return shape.getGlobalBounds(); }

	Block(float x, float y);
	Block();

	void render(sf::RenderTarget* target);
};