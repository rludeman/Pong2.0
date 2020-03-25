#pragma once

#include <SFML/Graphics.hpp>

#include "GameState.h"

class Pong
{
public:
	Pong(const sf::Font* fontPtr, const sf::RenderWindow& window);
	~Pong();

	void handleEvents(const sf::Event& event, sf::RenderWindow& window, GameState& currentState);
	void draw(sf::RenderWindow& window);

private:
	int scoreA;
	int scoreB;
	const sf::Font* fontPtr;
	sf::CircleShape ball;
	sf::RectangleShape paddleA;
	sf::RectangleShape paddleB;
};

