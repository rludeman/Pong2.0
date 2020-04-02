#include <iostream>
#include "PongGame.h"



PongGame::PongGame()
{
}


PongGame::~PongGame()
{
}

Levels PongGame::handleEvents(const sf::Event & event, sf::RenderWindow & window)
{
	if (event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Space: // TODO disable after launch
			ball.setVelocity(sf::Vector2f(-Ball::DefaultSpeed, Ball::DefaultSpeed));
			break;

		case sf::Keyboard::W:
			paddleA.moveUp();
			break;

		case sf::Keyboard::S:
			paddleA.moveDown();
			break;

		case sf::Keyboard::Escape:
			reset(window);
			return Levels::Menu;
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
	return Levels::Game;
}

void PongGame::update(const sf::Time deltaTime, const sf::RenderWindow& window)
{
	ball.update(deltaTime, window, paddleA, paddleB);
	ai.udpate(ball);
	paddleA.update(deltaTime, window);
	paddleB.update(deltaTime, window);

	if (checkScore(ball, window))
		reset(window);
}

void PongGame::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Text score(std::to_string(scoreA) + " | " + std::to_string(scoreB), font, 40);
	target.draw(score);
	target.draw(ball);
	target.draw(paddleA);
	target.draw(paddleB);
	if (scoreA >= 5)
	{
		target.draw(winMsg);
	}
	if (scoreB >= 5)
	{
		target.draw(loseMsg);
	}
}

bool PongGame::init(const sf::RenderWindow& window)
{
	// Load Font
	if (!font.loadFromFile("FreeSansBold.ttf"))
	{
		std::cout << "Failed to load font." << std::endl;
		return false;
	}

	// Paddles
	paddleA.setSize(sf::Vector2f(10, 100));
	paddleB.setSize(sf::Vector2f(10, 100));
	paddleA.setPosition(10.f, window.getSize().y / 2.f - 50.f);
	paddleB.setPosition(window.getSize().x - 10.f, window.getSize().y / 2.f - 50.f);

	// Ball
	ball.setRadius(10.f);
	ball.setOrigin(ball.getRadius(), ball.getRadius());
	ball.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);

	// AI Controller
	ai.setPaddle(&paddleB);

	// Winner/Loser Messages
	winMsg.setFont(font);
	winMsg.setCharacterSize(100);
	winMsg.setPosition(200, 200);
	winMsg.setString("You Win!");
	loseMsg.setFont(font);
	loseMsg.setCharacterSize(100);
	loseMsg.setPosition(200, 200);
	loseMsg.setString("You Lose");

	return true;
}

void PongGame::reset(const sf::RenderWindow & window)
{
	paddleA.setPosition(10.f, window.getSize().y / 2.f - 50.f);
	paddleB.setPosition(window.getSize().x - 10.f, window.getSize().y / 2.f - 50.f);
	ball.setVelocity(sf::Vector2f(0.f, 0.f));
	ball.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
}

bool PongGame::checkScore(const Ball & ball, const sf::RenderWindow & window)
{
	if (ball.getPosition().x < 0.f)
	{
		++scoreB;
		return true;
	}
	if (ball.getPosition().x > window.getSize().x)
	{
		++scoreA;
		return true;
	}
	return false;
}
