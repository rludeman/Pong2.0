#include <iostream>
#include "Pong.h"


Pong::Pong(const sf::RenderWindow& window)
{
	// Initialize game state
	if (!changeLevel(Levels::Menu, window))
		throw(std::exception("Failed to initialize game."));
}

Pong::~Pong()
{
}

void Pong::handleEvents(const sf::Event & event, sf::RenderWindow & window)
{
	Levels nextState;
	nextState = currentLevel->handleEvents(event, window);
	if (nextState != currentState)
		changeLevel(nextState, window);
}

void Pong::update(sf::Time deltaTime, const sf::RenderWindow& window) // TODO implement physics/collisions
{
	currentLevel->update(deltaTime, window);
}

void Pong::draw(sf::RenderWindow & window) // TODO make components 'drawable' so we can "window.draw(game)"
{
	currentLevel->draw(window);
}

bool Pong::changeLevel(Levels level, const sf::RenderWindow& window)
{
	bool result = false;
	switch (level)
	{
	case Menu:
		currentState = Levels::Menu;
		currentLevel.reset(new StartScreen());
		result = currentLevel->init(window);			
		break;
	case Game:
		currentState = Levels::Game;
		currentLevel.reset(new PongGame());
		result = currentLevel->init(window);
		break;
	}
	if (!result)
		std::cout << "Failed to load level: " << level << std::endl; // TODO overwrite << operator for Levels enum
	return result;
}
