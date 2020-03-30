#pragma once

#include <SFML/Graphics.hpp>

#include "GameLevel.h"
#include "StartScreen.h"
#include "PongGame.h"

class Pong
{
public:
	Pong(const sf::RenderWindow& window);
	~Pong();

	void handleEvents(const sf::Event& event, sf::RenderWindow& window);
	void update(sf::Time deltaTime, const sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);

private:
	bool changeLevel(Levels level, const sf::RenderWindow& window);

private:
	// Current Level/State
	Levels currentState;
	std::unique_ptr<GameLevel> currentLevel;
};

