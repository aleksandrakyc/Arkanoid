#include "pch.h"

void Menu::initVars()
{
	this->window = nullptr;
	this->game = nullptr;
	this->scoreboard = nullptr;
}

void Menu::initGame()
{
	this->game = new Game();
}

void Menu::initScoreboard()
{
	this->scoreboard = new Scoreboard();
}

Menu::Menu()
{
	initVars();
	initWindow();
}

Menu::~Menu()
{
	delete this->window;
	delete this->game;
	delete this->scoreboard;
}

void Menu::update()
{
	pollEvents();

	if (buttonGame.update(this->ev, this->window))
	{

		this->window->setVisible(false); //or close it

		initGame();
		this->game->run();
		this->window->setVisible(true);

	}
	else if (buttonQuit.update(this->ev, this->window))
	{
		this->window->close();

	}
	else if (buttonScore.update(this->ev, this->window))
	{
		this->window->setVisible(false); 
		this->initScoreboard();
		this->scoreboard->run();
		this->window->setVisible(true);
	}
}

void Menu::render()
{
	this->window->clear();
	//stuffs
	this->buttonGame.render(this->window);
	this->buttonQuit.render(this->window);
	this->buttonScore.render(this->window);

	sf::Text buttonGame, buttonQuit, buttonScore;
	buttonGame.setFont(this->font); 
	buttonGame.setString("Play");
	buttonGame.setCharacterSize(60);
	buttonGame.setPosition(500,100);

	buttonQuit.setFont(this->font); 
	buttonQuit.setString("Quit");
	buttonQuit.setCharacterSize(60);
	buttonQuit.setPosition(500, 600);

	buttonScore.setFont(this->font);
	buttonScore.setString("Scores");
	buttonScore.setCharacterSize(60);
	buttonScore.setPosition(500, 350);

	this->window->draw(buttonGame);
	this->window->draw(buttonQuit);
	this->window->draw(buttonScore);
	//
	this->window->display();
}
