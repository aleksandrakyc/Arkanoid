#pragma once
#include <list>
#include <memory>
#include <filesystem>
#include <ranges>
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
	void sortScores();

public:
	Scoreboard();

	void update();
	void render();
	void run();

};