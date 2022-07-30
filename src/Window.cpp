#include "pch.h"

void Window::initVars()
{
	this->window = nullptr;
}

void Window::initWindow()
{
	this->videoMode.height = GlobalVars::height;
	this->videoMode.width = GlobalVars::width;

	this->window = new sf::RenderWindow(this->videoMode, "title", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Window::initFont()
{

	if (!font.loadFromFile("resources/ARCADECLASSIC.ttf"))
	{
		
		std::cout << "nie da sie za³adowaæ czcionki" << std::endl;
	}

}

Window::Window()
{
	initVars();
	initFont();
}

Window::~Window()
{

}

const bool Window::getWindowIsOpen()
{
	return this->window->isOpen();
}

void Window::pollEvents()
{
	while (this->window->pollEvent(this->ev)) {

		switch (ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}

	}
}
