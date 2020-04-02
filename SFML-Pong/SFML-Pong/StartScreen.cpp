#include <iostream>
#include "StartScreen.h"

StartScreen::StartScreen() 
{
}


StartScreen::~StartScreen()
{
}

bool StartScreen::init(const sf::RenderWindow& window) 
{
	// Load Font
	if (!font.loadFromFile("FreeSansBold.ttf"))
	{
		std::cout << "Failed to load font." << std::endl;
		return false;
	}

	// Title
	title.setCharacterSize(50);
	title.setPosition(10, 10);
	title.setFont(font);
	title.setString("SFML-Pong!");

	// Play Button
	playButton.box.setSize(sf::Vector2f(150, 50));
	playButton.box.setPosition(10, 70);
	playButton.box.setFillColor(sf::Color::Black);
	playButton.box.setOutlineThickness(2);
	playButton.msg.setCharacterSize(40);
	playButton.msg.setPosition(10, 70);
	playButton.msg.setFont(font);
	playButton.msg.setString("Play");

	// Quit Button
	quitButton.box.setSize(sf::Vector2f(150, 50));
	quitButton.box.setPosition(10, 130);
	quitButton.box.setFillColor(sf::Color::Black);
	quitButton.box.setOutlineThickness(2);
	quitButton.msg.setCharacterSize(40);
	quitButton.msg.setPosition(10, 130);
	quitButton.msg.setFont(font);
	quitButton.msg.setString("Quit");

	return true;
}

Levels StartScreen::handleEvents(const sf::Event& event, sf::RenderWindow& window)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Button::Left)
		{
			sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
			if (playButton.box.getGlobalBounds().contains(mousePos))
				return Levels::Game;
			if (quitButton.box.getGlobalBounds().contains(mousePos))
				window.close();
		}
	}
	return Levels::Menu;
}

void StartScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(title);
	target.draw(playButton.box);
	target.draw(playButton.msg);
	target.draw(quitButton.box);
	target.draw(quitButton.msg);
}
