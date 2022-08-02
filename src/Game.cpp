#include "pch.h"


void Game::initVars()
{
	this->window = nullptr;
	this->paddle = nullptr;
	this->ball = nullptr;
	this->score = nullptr;
}

void Game::initPaddle()
{
	this->paddle = new Paddle(550, 700);
}

void Game::initBall()
{
	this->ball = new Ball();
}

void Game::initBrickWall()
{

	for (int i = 0; i < GlobalVars::width; i+=100) {
		for (int j = 0; j< (GlobalVars::height - 400); j+=40)
		brickWall.push_back(std::unique_ptr<Brick>(new Brick(i, j)));
	}

}

void Game::initScore()
{
	this->score = new Score();
}

void Game::renderWall()
{
	for (auto &it : brickWall) {

		it->render(this->window);

	}
}

void Game::updateWall()
{

	auto it = this->brickWall.begin();

	while (it != this->brickWall.end()) {

		if (this->ball->checkCollision(**it)) {
						
			it = this->brickWall.erase(it);
			this->ball->move();
			this->score->increment();
		}
		else {
			it++;
		}
	}
}

std::string Game::getTextInput()
{
	std::string input;
	
	while (this->window->pollEvent(this->ev)) {

		switch (ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape) {
				
				this->window->close();
			}
			break;
		case sf::Event::TextEntered:
			if (this->ev.text.unicode < 128) {
				input += ev.text.unicode;
			}
			break;
		}

	}
	return input;
}

Game::Game()
{
	initVars();
	initPaddle();
	initBall();
	initWindow();
	initBrickWall();
	initScore();
}

Game::~Game()
{
	if (this->score->setMail(this->textBuf)) {
		this->score->saveToFile();
	}

	//delete this->window;
	delete this->paddle;
	delete this->ball;
	delete this->score;


}

void Game::run()
{
	while (this->getWindowIsOpen()) {

		if (gameOver==true) {

			this->displayScore();


		}
		else {

			this->update();

			this->render();
		}
	}
}


void Game::update()
{
	pollEvents();

	this->paddle->update();

	if (this->ball->clickStart(this->ev)) {

		this->ball->update();
		if(this->ball->checkCollision(*this->paddle)) {
			this->score->comboReset();
		}
		if (this->ball->checkFall()) {
			gameOver = true;
		}
		this->updateWall();
		this->ball->move();
	}
}

void Game::render()
{
	this->window->clear();

	//draw game
	this->paddle->render(this->window);
	this->ball->render(this->window);
	this->renderWall();


	this->window->display();
}

void Game::displayScore()
{
	sf::Text score = sf::Text(this->score->getScore(), this->font, 60);
	
	score.setPosition(GlobalVars::width / 2 - 100, GlobalVars::height / 2);
	

	sf::Text scoreDesc = sf::Text("Your score:", this->font, 60);

	scoreDesc.setPosition(100, GlobalVars::height / 2 - 100);


	sf::Text playerInput = sf::Text("", this->font, 24);

	playerInput.setPosition(GlobalVars::width / 2 - 100, GlobalVars::height - 200);


	sf::Text piDesc = sf::Text("Type your email and quit to save your score!", this->font, 24);

	piDesc.setPosition(100, GlobalVars::height - 300);


	this->textBuf+=this->getTextInput();
	playerInput.setString(textBuf);

	this->window->clear();

	this->window->draw(score);
	this->window->draw(scoreDesc);
	this->window->draw(playerInput);
	this->window->draw(piDesc);

	this->window->display();
}
