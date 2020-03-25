#include <iostream>
#include "Pong.h"


Pong::Pong(const sf::Font* fontPtr, const sf::RenderWindow& window) : fontPtr(fontPtr)
{
	// Paddles
	paddleA.setSize(sf::Vector2f(10, 100));
	paddleA.setPosition(10.f, window.getSize().y / 2.f - 50.f);
	paddleB.setSize(sf::Vector2f(10, 100));
	paddleB.setPosition(window.getSize().x - 10.f, window.getSize().y / 2.f - 50.f);

	// Ball
	ball.setRadius(10.f);
	ball.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
}

Pong::~Pong()
{
}

void Pong::handleEvents(const sf::Event & event, sf::RenderWindow & window, GameState & currentState)
{
	if (event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Space:
			std::cout << "Game Start!" << std::endl;
			break;

		case sf::Keyboard::W:
			paddleA.moveUp();
			break;

		case sf::Keyboard::S:
			paddleA.moveDown();
			break;

		case sf::Keyboard::Escape:
			currentState = Menu;
			break;
		}
	}
	else if (event.type == sf::Event::KeyReleased)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::W:
			paddleA.moveDown();
			break;

		case sf::Keyboard::S:
			paddleA.moveUp();
			break;

		}
	}
}

void Pong::update(sf::Time deltaTime, const sf::RenderWindow & window)
{
	paddleA.update(deltaTime, window);
	paddleB.update(deltaTime, window);
}

void Pong::draw(sf::RenderWindow & window)
{
	sf::Text score(std::to_string(scoreA) + " | " + std::to_string(scoreB), *fontPtr, 40);
	window.draw(score);
	window.draw(ball);
	window.draw(paddleA);
	window.draw(paddleB);
}
