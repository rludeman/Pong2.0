#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

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

	// Game State
	enum GameState { Menu, Game };
	GameState currentState = Menu;

	// Start Screen
	sf::Text title;
	title.setFont(font);
	title.setCharacterSize(50);
	title.setPosition(10, 10);
	title.setString("SFML-Pong!");

	// Play Button
	sf::RectangleShape playButton(sf::Vector2f(150, 50));
	playButton.setPosition(10, 70);
	playButton.setFillColor(sf::Color::Black);
	playButton.setOutlineThickness(2);

	sf::Text playButtonMsg;
	playButtonMsg.setFont(font);
	playButtonMsg.setCharacterSize(40);
	playButtonMsg.setPosition(10, 70);
	playButtonMsg.setString("Play");

	// Quit Button
	sf::RectangleShape quitButton(sf::Vector2f(150, 50));
	quitButton.setPosition(10, 130);
	quitButton.setFillColor(sf::Color::Black);
	quitButton.setOutlineThickness(2);

	sf::Text quitButtonMsg;
	quitButtonMsg.setFont(font);
	quitButtonMsg.setCharacterSize(40);
	quitButtonMsg.setPosition(10, 130);
	quitButtonMsg.setString("Quit");

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
				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Button::Left)
					{
						sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
						if (playButton.getGlobalBounds().contains(mousePos))
							currentState = Game;
						if (quitButton.getGlobalBounds().contains(mousePos))
							window.close();
					}
				}
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
			window.draw(title);
			window.draw(playButton);
			window.draw(playButtonMsg);
			window.draw(quitButton);
			window.draw(quitButtonMsg);
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