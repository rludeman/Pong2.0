#include "Paddle.h"



Paddle::Paddle() : velocity(0.f, 0.f)
{
}


Paddle::~Paddle()
{
}

void Paddle::moveUp() { velocity -= sf::Vector2f(0.f, DefaultSpeed); }
void Paddle::moveDown() { velocity += sf::Vector2f(0.f, DefaultSpeed); }

void Paddle::update(sf::Time deltaTime, const sf::RenderWindow & window)
{
	sf::Vector2f deltaPos = velocity * deltaTime.asSeconds();
	setPosition(getPosition() + deltaPos);
	if (getPosition().y < 0)
		setPosition(getPosition().x, 0.f);
	else if (getPosition().y > window.getSize().y)
		setPosition(getPosition().x, static_cast<float>(window.getSize().y));
}
