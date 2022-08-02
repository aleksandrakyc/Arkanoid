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
	
	this->buttonGame.render(this->window);
	this->buttonQuit.render(this->window);
	this->buttonScore.render(this->window);

	sf::Text textGame = sf::Text("Play", this->font, 60);
	textGame.setPosition(500,100);

	sf::Text textQuit = sf::Text("Quit", this->font, 60);
	textQuit.setPosition(500, 600);

	sf::Text textScore = sf::Text("Score", this->font, 60);
	textScore.setPosition(500, 350);

	this->window->draw(textGame);
	this->window->draw(textQuit);
	this->window->draw(textScore);
	//
	this->window->display();
}
