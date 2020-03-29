#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

#include "GameState.h"	// Levels definition

class GameLevel
{
public:
	virtual bool init(const sf::RenderWindow& window) = 0;
	virtual Levels handleEvents(const sf::Event& event, sf::RenderWindow& window) = 0;
	virtual void update(const sf::Time deltaTime, const sf::RenderWindow& window) {};
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual ~GameLevel() {};
};

