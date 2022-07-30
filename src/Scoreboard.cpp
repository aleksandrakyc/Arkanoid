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

void Scoreboard::sortScores()
{
	std::ranges::sort(this->scores);

}

Scoreboard::Scoreboard()
{
	initWindow();
	loadScores();
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

	sf::Text buttonQuit;

	buttonQuit.setFont(this->font);
	buttonQuit.setString("Quit");
	buttonQuit.setCharacterSize(60);
	buttonQuit.setPosition(500, 600);

	this->window->draw(buttonQuit);
	//
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
