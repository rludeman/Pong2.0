#include <iostream>
#include "Pong.h"


Pong::Pong(const sf::Font* fontPtr, const sf::RenderWindow& window) : fontPtr(fontPtr)
{
	// TODO move default initialization to constructors
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

	// Winner Message
	winMsg.setFont(*fontPtr);
	winMsg.setCharacterSize(100);
	winMsg.setPosition(200, 200);
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
			ball.setVelocity(sf::Vector2f(-Ball::DefaultSpeed, Ball::DefaultSpeed)); // TODO disable after launch
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

void Pong::update(sf::Time deltaTime, const sf::RenderWindow & window) // TODO implement scoring/winning
{
	ball.update(deltaTime, window, paddleA, paddleB);
	ai.udpate(ball);
	paddleA.update(deltaTime, window);
	paddleB.update(deltaTime, window);
	
	if (checkScore(ball, window))
		reset(window);
}

void Pong::draw(sf::RenderWindow & window) // TODO make components 'drawable' so we can "window.draw(game)"
{
	sf::Text score(std::to_string(scoreA) + " | " + std::to_string(scoreB), *fontPtr, 40);
	window.draw(score);
	window.draw(ball);
	window.draw(paddleA);
	window.draw(paddleB);
	if (scoreA >= 5)
	{
		winMsg.setString("You Win!");
		window.draw(winMsg);
	}
	if (scoreB >= 5)
	{
		winMsg.setString("You Lose");
		window.draw(winMsg);
	}
}

void Pong::reset(const sf::RenderWindow& window)
{
	paddleA.setPosition(10.f, window.getSize().y / 2.f - 50.f);
	paddleB.setPosition(window.getSize().x - 10.f, window.getSize().y / 2.f - 50.f);
	ball.setVelocity(sf::Vector2f(0.f, 0.f));
	ball.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
}

bool Pong::checkScore(const Ball& ball, const sf::RenderWindow& window)
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
