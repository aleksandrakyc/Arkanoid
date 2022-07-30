#include "pch.h"

Block::Block(float x, float y)
{
}

Block::Block()
{
}

void Block::render(sf::RenderTarget* target)
{

	target->draw(this->shape);
}
