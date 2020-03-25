#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>

// A moving circle
class Ball: public sf::CircleShape
{
public:
	Ball();
	~Ball();

	static const float DefaultSpeed;

	void update(const sf::Time deltaTime, const sf::RenderWindow& window, sf::RectangleShape paddleA, sf::RectangleShape paddleB);
	void setVelocity(sf::Vector2f newVelocity);
	sf::Vector2f getVelocity();

private:
	sf::Vector2f velocity;
};

