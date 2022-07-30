#pragma once

class Paddle
	:public Block
{

	float speed = 10;
	void initShape();

public:
	
	Paddle(float x, float y);

	void update();
};