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

	sf::Font font;
	if (!font.loadFromFile("FreeSansBold.ttf")) // TODO create class for handling assets
	{
		std::cout << "Failed to load font." << std::endl;
		return 1;
	}

	Pong game(&font, window);
	
	sf::Clock loopClock; // Clock starts automatically
	sf::Time deltaTime;	

	sf::Event event;

	// Game loop
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			game.handleEvents(event, window);
		}

		deltaTime = loopClock.restart();

		window.clear();

		game.update(deltaTime, window);
		game.draw(window);

		window.display();
	}

	return 0;
}