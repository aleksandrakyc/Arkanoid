#include "pch.h"

void Scoreboard::drawScoreboard()
{
	sf::Text score;
	score.setFont(this->font); 
	score.setCharacterSize(24);
	score.setPosition(550,100);

	std::string buf;
	std::stringstream ss;
	for (auto it : scores) {
		ss << it <<'\n';
		ss >> buf;
	}

	score.setString(buf);
	this->window->draw(score);
}

bool Scoreboard::loadScores()
{
	int scorei;
	std::string email;
	
	std::fstream fs;
	fs.open(this->path, std::fstream::in);

	if (fs.is_open()) {
		
		fs >> email;
		fs >> scorei;

		Score score(scorei, email);
		scores.push_back(scorei);
		this->scoreboard.push_back(std::make_unique<Score>(score));

		return true;
	}

	fs.close();
	return false;
}


Scoreboard::Scoreboard()
{
	initWindow();
	loadScores();
}

Scoreboard::~Scoreboard()
{
	//delete window;
}

void Scoreboard::update()
{
	pollEvents();
	if (buttonQuit.update(this->ev, this->window))
	{
		this->window->close();

	}
}

void Scoreboard::render()
{
	this->window->clear();

	drawScoreboard();

	this->buttonQuit.render(this->window);

	sf::Text textQuit = sf::Text("Quit", this->font, 60);

	textQuit.setPosition(500, 600);

	this->window->draw(textQuit);
	
	this->window->display();
}

void Scoreboard::run()
{
	while (this->getWindowIsOpen()) {

		//update
			
		this->update();

		//render

		this->render();
		
	}
}
