#include <iostream>
#include "Pong.h"


Pong::Pong(const sf::Font* fontPtr, const sf::RenderWindow& window) : currentState(Menu)	
{
	menu.setFont(*fontPtr);	// TODO handle fonts/assets more uniformly
	game.init(fontPtr, window);
}

Pong::~Pong()
{
}

void Pong::handleEvents(const sf::Event & event, sf::RenderWindow & window)
{
	switch (currentState)
	{
	case Menu:
		menu.handleEvents(event, window);
		break;

	case Game:
		game.handleEvents(event, window);
		break;
	}
}

void Pong::update(sf::Time deltaTime, const sf::RenderWindow& window) // TODO implement physics/collisions
{
	game.update(deltaTime, window);
}

void Pong::draw(sf::RenderWindow & window) // TODO make components 'drawable' so we can "window.draw(game)"
{
	switch (currentState)
	{
	case Menu:
		menu.draw(window); // TODO wrap up game-states in class.  Reevaluate what's in Pong and what may belong outside it.
		break;

	case Game:
		game.draw(window);
		break;
	}
}
