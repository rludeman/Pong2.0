#include <iostream>	// TODO cleanup unnecessary libraries
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "StartScreen.h"
#include "Pong.h"
#include "GameState.h"

// TODO Document everything!!!
int main()
{
	// Initialization
	sf::RenderWindow window(sf::VideoMode(800,600), "SFML-Pong");
	window.setKeyRepeatEnabled(false);

	sf::Font font;
	if (!font.loadFromFile("FreeSansBold.ttf"))
	{
		std::cout << "Failed to load font." << std::endl;
		return 1;
	}

	GameState currentState = Menu;

	StartScreen menu(font);

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

			switch (currentState)
			{
			case Menu:
				menu.handleEvents(event, window, currentState);
				break;
				
			case Game:
				game.handleEvents(event, window, currentState);
				if (currentState == Menu) // Just left game screen
					game.reset(window);
				break;
			}
		}

		deltaTime = loopClock.restart();

		window.clear();

		switch (currentState)
		{
		case Menu:
			menu.draw(window); // TODO wrap up game-states in class.  Reevaluate what's in Pong and what may belong outside it.
			break;

		case Game:
			game.update(deltaTime, window);
			game.draw(window);
			break;
		}

		window.display();
	}

	return 0;
}