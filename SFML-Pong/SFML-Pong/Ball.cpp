#include <iostream>
#include "Ball.h"

const float Ball::DefaultSpeed = 200.f; // TODO tune speed

Ball::Ball(): velocity(0.f, 0.f)
{
}

Ball::~Ball()
{
}

void Ball::update(const sf::Time deltaTime, const sf::RenderWindow & window) // TODO implement collision with paddles
{
	sf::Vector2f deltaPos = velocity * deltaTime.asSeconds();
	move(deltaPos);
	if (getPosition().y - getRadius() < 0 || getPosition().y + getRadius() > window.getSize().y)
		velocity.y = -velocity.y;
}

void Ball::setVelocity(sf::Vector2f newVelocity) { velocity = newVelocity; }

sf::Vector2f Ball::getVelocity() { return velocity; }
