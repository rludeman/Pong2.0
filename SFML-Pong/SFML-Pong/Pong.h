#pragma once

#include <SFML/Graphics.hpp>

#include "GameState.h"
#include "Ball.h"
#include "Paddle.h"

class Pong
{
public:
	Pong(const sf::Font* fontPtr, const sf::RenderWindow& window);
	~Pong();

	void handleEvents(const sf::Event& event, sf::RenderWindow& window, GameState& currentState);
	void update(sf::Time deltaTime, const sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	void reset(const sf::RenderWindow& window);

private:
	int scoreA;
	int scoreB;
	const sf::Font* fontPtr;
	Ball ball;
	Paddle paddleA;
	Paddle paddleB;
};

