#pragma once
#include <iostream>
class Window
{
protected:

	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	sf::Font font;

	void initVars();
	void initWindow();
	void initFont();

public:
	Window();
	~Window();

	const bool getWindowIsOpen();

	void pollEvents();
	virtual void update() = 0;
	virtual void render() = 0;
};