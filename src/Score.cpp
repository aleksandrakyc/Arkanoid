#include "pch.h"

Score::Score()
{
}

Score::Score(int score, const std::string& mail) : score(score), email(mail)
{
}

bool Score::setMail(const std::string& mail)
{
	if (std::regex_match(mail, regex_mail)) {

		this->email = mail;
		return true;
	}

	return false;
}

bool Score::saveToFile()
{
	std::fstream fs;
	fs.open(this->path, std::fstream::app);

	if (fs.is_open()) {
		fs << this->email << '\n' << this->score << '\n';
		return true;
	}

	fs.close();

	return false;
}

void Score::increment()
{
	this->score += 100;
	this->score *= this->combo;
	std::cout << score << std::endl;
}

std::string Score::getScore()
{
	std::stringstream ss;
	std::string scorestr;

	ss << int(score);
	ss >> scorestr;

	return scorestr;
}

int Score::getScoreInt()
{
	return score;
}

void Score::comboReset()
{
	this->combo = 1.f;
}

