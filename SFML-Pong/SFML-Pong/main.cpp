#include <iostream>	// TODO cleanup unnecessary libraries
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Pong.h"


int main()
{
	// Initialization
	sf::RenderWindow window(sf::VideoMode(800,600), "SFML-Pong");
	window.setKeyRepeatEnabled(false);

	// Load game
	Pong game(window);
	
	// Instantiate loop objects
	sf::Clock loopClock;
	sf::Time deltaTime;
	sf::Event event;

	// Game loop
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			// Handle game events
			game.handleEvents(event, window);
		}

		// Capture time since last loop
		deltaTime = loopClock.restart();

		// Clear buffer
		window.clear();

		// Update game state and objects
		game.update(deltaTime, window);

		// Draw game objects to buffer
		window.draw(game);

		// Render buffer to window
		window.display();
	}

	return 0;
}