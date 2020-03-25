#include "StartScreen.h"

StartScreen::StartScreen(const sf::Font& font) // TODO layout components better. Consider creating class for buttons
{
	// Title
	title.setFont(font);
	title.setCharacterSize(50);
	title.setPosition(10, 10);
	title.setString("SFML-Pong!");

	// Play Button
	playButton.box.setSize(sf::Vector2f(150, 50));
	playButton.box.setPosition(10, 70);
	playButton.box.setFillColor(sf::Color::Black);
	playButton.box.setOutlineThickness(2);
	playButton.msg.setFont(font);
	playButton.msg.setCharacterSize(40);
	playButton.msg.setPosition(10, 70);
	playButton.msg.setString("Play");

	// Quit Button
	quitButton.box.setSize(sf::Vector2f(150, 50));
	quitButton.box.setPosition(10, 130);
	quitButton.box.setFillColor(sf::Color::Black);
	quitButton.box.setOutlineThickness(2);
	quitButton.msg.setFont(font);
	quitButton.msg.setCharacterSize(40);
	quitButton.msg.setPosition(10, 130);
	quitButton.msg.setString("Quit");
}


StartScreen::~StartScreen()
{
}

void StartScreen::handleEvents(const sf::Event& event, sf::RenderWindow& window, GameState& currentState)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Button::Left)
		{
			sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
			if (playButton.box.getGlobalBounds().contains(mousePos))
				currentState = Game;
			if (quitButton.box.getGlobalBounds().contains(mousePos))
				window.close();
		}
	}
}

void StartScreen::draw(sf::RenderWindow& window) // TODO make 'drawable'
{
	window.draw(title);
	window.draw(playButton.box);
	window.draw(playButton.msg);
	window.draw(quitButton.box);
	window.draw(quitButton.msg);
}
