#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>

// A moving rectangle
class Paddle: public sf::RectangleShape
{
public:
	Paddle();
	~Paddle();

	static const float DefaultSpeed; // TODO make static

	void moveUp();
	void moveDown();
	void update(sf::Time deltaTime, const sf::RenderWindow& window);

private:
	sf::Vector2f velocity; 
};

