#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "StartScreen.h"
#include "GameState.h"

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

	// Game Objects
	sf::Text scoreboard;
	scoreboard.setFont(font);
	scoreboard.setCharacterSize(40);
	scoreboard.setPosition(0, 0);
	scoreboard.setString("0 | 0");

	// Paddles
	sf::RectangleShape paddleLeft(sf::Vector2f(10, 100));
	paddleLeft.setPosition(10.f, window.getSize().y / 2.f - 50.f);
	
	sf::RectangleShape paddleRight(sf::Vector2f(10, 100));
	paddleRight.setPosition(window.getSize().x - 10.f, window.getSize().y / 2.f - 50.f);

	// Ball
	sf::CircleShape ball(10.f);
	ball.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
	
	sf::Event event;

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
				if (event.type == sf::Event::KeyPressed)
				{
					switch (event.key.code)
					{
					case sf::Keyboard::Space:
						std::cout << "Game Start!" << std::endl;
						break;

					case sf::Keyboard::W:
						std::cout << "Move Up!" << std::endl;
						break;

					case sf::Keyboard::S:
						std::cout << "Move Down!" << std::endl;
						break;

					case sf::Keyboard::Escape:
						currentState = Menu;
						break;
					}
				}
				break;
			}
		}

		window.clear();

		switch (currentState)
		{
		case Menu:
			menu.draw(window);
			break;

		case Game:
			window.draw(scoreboard);
			window.draw(ball);
			window.draw(paddleLeft);
			window.draw(paddleRight);
			break;
		}

		window.display();
	}

	return 0;
}