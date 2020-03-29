#include <iostream>
#include "Pong.h"


Pong::Pong(const sf::Font* fontPtr, const sf::RenderWindow& window)
{
	game.init(window);

	// Initialize game state
	currentState = Levels::Menu;
	menu.init(window);
	currentLevel = &menu;
}

Pong::~Pong()
{
}

void Pong::handleEvents(const sf::Event & event, sf::RenderWindow & window)
{
	Levels nextState;
	nextState = currentLevel->handleEvents(event, window);
	if (nextState != currentState)
		changeLevel(nextState);
}

void Pong::update(sf::Time deltaTime, const sf::RenderWindow& window) // TODO implement physics/collisions
{
	currentLevel->update(deltaTime, window);
}

void Pong::draw(sf::RenderWindow & window) // TODO make components 'drawable' so we can "window.draw(game)"
{
	currentLevel->draw(window);
}

void Pong::changeLevel(Levels level)
{
	switch (level)
	{	// TODO include initialization/destruction with level switch
	case Menu:
		currentState = Levels::Menu;
		currentLevel = &menu;
		break;
	case Game:
		currentState = Levels::Game;
		currentLevel = &game;
		break;
	}
}
