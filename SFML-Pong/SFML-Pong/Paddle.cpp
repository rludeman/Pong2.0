#include "Paddle.h"

const float Paddle::DefaultSpeed = 250.f;

Paddle::Paddle() : velocity(0.f, 0.f)
{
}


Paddle::~Paddle()
{
}

void Paddle::moveUp() 
{ 
	if (velocity.y >= 0.f)
		velocity -= sf::Vector2f(0.f, DefaultSpeed); 
}

void Paddle::moveDown() 
{
	if (velocity.y <= 0.f)
		velocity += sf::Vector2f(0.f, DefaultSpeed);
}

void Paddle::update(sf::Time deltaTime, const sf::RenderWindow & window) 
{
	sf::Vector2f deltaPos = velocity * deltaTime.asSeconds();
	move(deltaPos); 
	if (getPosition().y < 0)
		setPosition(getPosition().x, 0.f);
	else if (getPosition().y + getSize().y > window.getSize().y)
		setPosition(getPosition().x, window.getSize().y - getSize().y);
}
