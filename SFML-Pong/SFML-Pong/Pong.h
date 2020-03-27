#pragma once

#include <SFML/Graphics.hpp>

#include "StartScreen.h"
#include "GameState.h"
#include "Ball.h"
#include "Paddle.h"
#include "AIController.h"


class Pong
{
public:
	Pong(const sf::Font* fontPtr, const sf::RenderWindow& window);
	~Pong();

	void handleEvents(const sf::Event& event, sf::RenderWindow& window);
	void update(sf::Time deltaTime, const sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	void reset(const sf::RenderWindow& window);

	GameState getState();

private:
	bool checkScore(const Ball& ball, const sf::RenderWindow& window);

private:	// TODO add background
	StartScreen menu;	// TODO Wrap game state classes ("Levels") in class
	GameState currentState;
	int scoreA;	// TODO wrap scoreboard in class
	int scoreB;
	const sf::Font* fontPtr;
	sf::Text winMsg;	// TODO figure out way to better manage on the fly assets
	Ball ball;	// TODO wrap game components in their own class
	Paddle paddleA;
	Paddle paddleB;
	AIController ai;
};

