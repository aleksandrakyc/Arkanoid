#pragma once

#ifndef GAME_H
#define GAME_H

#include <memory>
#include <list>
class Game
	: public Window
{
	bool gameOver = false;
	Paddle* paddle;
	Ball* ball;
	Score* score;
	std::list<std::unique_ptr<Brick>> brickWall;
	
	std::string textBuf;

	void initVars();
	void initPaddle();
	void initBall();
	void initBrickWall();
	void initScore();

	void renderWall();
	void updateWall();

	std::string getTextInput();
	
public:
	Game();
	~Game();

	void run();

	void update();
	void render();

	void displayScore();

};

#endif // !game.H
