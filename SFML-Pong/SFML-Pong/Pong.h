#pragma once

#include <SFML/Graphics.hpp>

#include "GameLevel.h"
#include "StartScreen.h"
#include "PongGame.h"

class Pong
{
public:
	Pong(const sf::Font* fontPtr, const sf::RenderWindow& window);
	~Pong();

	void handleEvents(const sf::Event& event, sf::RenderWindow& window);
	void update(sf::Time deltaTime, const sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);

private:
	void changeLevel(Levels level);

private:
	// Game States/Levels
	Levels currentState;	// Corresponds to currentLevel
	GameLevel* currentLevel;	// TODO couple currentState and currentLevel (propbably by doing vvthisvv)
	StartScreen menu;	// TODO Change GameLevels objects to pointers and initialize only when they're needed
	PongGame game;
	
};

