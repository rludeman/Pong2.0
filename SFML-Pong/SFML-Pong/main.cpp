#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800,600), "SFML-Pong");

	sf::Font font;
	if (!font.loadFromFile("FreeSansBold.ttf"))
	{
		std::cout << "Failed to load font." << std::endl;
		return 1;
	}

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
	
	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed && 
				event.mouseButton.button == sf::Mouse::Button::Left)
			{
				sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
				if (playButton.getGlobalBounds().contains(mousePos))
					std::cout << "Play Game!" << std::endl;
				if (quitButton.getGlobalBounds().contains(mousePos))
					window.close();
			}
		}

		window.clear();

		window.draw(title);
		window.draw(playButton);
		window.draw(playButtonMsg);
		window.draw(quitButton);
		window.draw(quitButtonMsg);

		window.display();
	}

	return 0;
}