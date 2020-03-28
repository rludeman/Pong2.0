#include "PongGame.h"



PongGame::PongGame()
{
}


PongGame::~PongGame()
{
}

void PongGame::handleEvents(const sf::Event & event, sf::RenderWindow & window)
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
			// currentState = Menu; TODO replace state change with "GameLevel" change
			reset(window);
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

void PongGame::update(const sf::Time deltaTime, const sf::RenderWindow& window)
{
	ball.update(deltaTime, window, paddleA, paddleB);
	ai.udpate(ball);
	paddleA.update(deltaTime, window);
	paddleB.update(deltaTime, window);

	if (checkScore(ball, window))
		reset(window);
}

void PongGame::draw(sf::RenderWindow & window)
{
	sf::Text score(std::to_string(scoreA) + " | " + std::to_string(scoreB), *fontPtr, 40);
	window.draw(score);
	window.draw(ball);
	window.draw(paddleA);
	window.draw(paddleB);
	if (scoreA >= 5)
	{
		winMsg.setString("You Win!"); // TODO End and reset game (score) with winning
		window.draw(winMsg);
	}
	if (scoreB >= 5)
	{
		winMsg.setString("You Lose");
		window.draw(winMsg);
	}
}

void PongGame::init(const sf::Font* fontPtr, const sf::RenderWindow & window)
{
	this->fontPtr = fontPtr;

	// TODO move default initialization to constructors and add setters/getters
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
