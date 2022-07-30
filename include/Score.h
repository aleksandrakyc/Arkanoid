#pragma once
#include <string>
#include <iostream> 
#include <regex>
#include <filesystem>
#include <sstream>
#include <fstream>

class Score
{
	float score = 0;
	float combo = 1.f;

	//delete this
	std::regex regex_mail = std::regex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	std::string email = "nie podano odpowiedniego adresu";

	std::filesystem::path path = "scoreboard.txt";

public:
	Score();
	Score(int score, const std::string& mail);

	bool setMail(const std::string& mail);
	bool saveToFile();

	std::string getScore();
	int getScoreInt();
	void test();
	
	void comboReset();
	void increment();
};