#pragma once

class Menu
	: public Window
{
	Button buttonGame = Button(450, 100);
	Button buttonScore = Button(450, 350);
	Button buttonQuit = Button(450, 600);
	
	Game* game;
	Scoreboard* scoreboard;
	void initVars();
	void initGame();
	void initScoreboard();

public:

	Menu();
	~Menu();

	void update();
	void render();
};