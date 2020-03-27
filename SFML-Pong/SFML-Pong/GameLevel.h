#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>


class GameLevel
{
public:
	virtual void handleEvents(const sf::Event& event, sf::RenderWindow& window) = 0;
	virtual void update(const sf::Time deltaTime, sf::RenderWindow& window) {};
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual ~GameLevel() {};
};

