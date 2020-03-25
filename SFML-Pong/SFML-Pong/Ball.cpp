#include <iostream>
#include "Ball.h"

const float Ball::DefaultSpeed = 200.f; // TODO tune speed

// TODO add physics like spin, acceleration, etc.

// TODO add visual 'highlight' to ball to see spin

Ball::Ball(): velocity(0.f, 0.f)
{
}

Ball::~Ball()
{
}

void Ball::update(const sf::Time deltaTime, const sf::RenderWindow & window, sf::RectangleShape paddleA, sf::RectangleShape paddleB) // TODO Prevent ball from gettting stuck in paddles/boundary
{
	sf::Vector2f deltaPos = velocity * deltaTime.asSeconds();
	move(deltaPos);
	// Boundary Collision
	if (getPosition().y - getRadius() < 0 || getPosition().y + getRadius() > window.getSize().y)
		velocity.y = -velocity.y;
	// Paddle Collision
	if (paddleA.getGlobalBounds().intersects(getGlobalBounds()) ||
		paddleB.getGlobalBounds().intersects(getGlobalBounds()))
		velocity.x = -velocity.x;	
}

void Ball::setVelocity(sf::Vector2f newVelocity) { velocity = newVelocity; }

sf::Vector2f Ball::getVelocity() { return velocity; }
