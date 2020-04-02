#include <iostream>
#include "Scoreboard.h"



Scoreboard::Scoreboard()
{
}


Scoreboard::~Scoreboard()
{
}

void Scoreboard::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(scoreboard);
}

bool Scoreboard::init()
{
	// Load Font
	if (!font.loadFromFile("FreeSansBold.ttf"))
	{
		std::cout << "Failed to load font." << std::endl;
		return false;
	}
	scoreA = scoreB = 0;
	scoreboard.setPosition(sf::Vector2f(0, 0));
	scoreboard.setFont(font);
	scoreboard.setCharacterSize(40);
	scoreboard.setFillColor(sf::Color::White);
	updateScore();
	return true;
}

void Scoreboard::incrementA()
{
	++scoreA;
	updateScore();
}

void Scoreboard::incrementB()
{
	++scoreB;
	updateScore();
}

int Scoreboard::getA() const
{
	return scoreA;
}

int Scoreboard::getB() const
{
	return scoreB;
}

void Scoreboard::updateScore()
{
	scoreboard.setString(std::to_string(scoreA) + " | " + std::to_string(scoreB));
}
