#pragma once
#include <list>
#include <memory>
#include <filesystem>
#include <vector>

class Scoreboard
	: public Window
{

	std::list<std::unique_ptr<Score>> scoreboard;
	Button buttonQuit = Button(450, 600);
	std::filesystem::path path = "scoreboard.txt";
	std::vector<int> scores;
	void drawScoreboard();

	bool loadScores();

public:
	Scoreboard();
	~Scoreboard();

	void update();
	void render();
	void run();

};