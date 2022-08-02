#pragma once

class Paddle
	:public Block
{

	float speed = 5;
	void initShape();

public:
	
	Paddle(float x, float y);

	void update();
};