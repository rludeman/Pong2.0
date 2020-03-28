#pragma once

#include <SFML/Graphics.hpp>

#include "GameState.h"
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
	// Game States/Levels
	GameState currentState;
	GameLevel* currentLevel;
	StartScreen menu;	// TODO Wrap game state classes ("Levels") in class
	PongGame game;
	
};

