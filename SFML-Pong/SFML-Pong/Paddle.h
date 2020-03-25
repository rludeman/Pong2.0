#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>

// A moving rectangle
class Paddle: public sf::RectangleShape
{
public:
	Paddle();
	~Paddle();

	const float DefaultSpeed = 250.f; 

	void moveUp();
	void moveDown();
	void update(sf::Time deltaTime, const sf::RenderWindow& window);

private:
	sf::Vector2f velocity;
};

