#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>

#include "GameState.h"	// Levels definition

class GameLevel: public sf::Drawable
{
public:
	virtual bool init(const sf::RenderWindow& window) = 0;
	virtual Levels handleEvents(const sf::Event& event, sf::RenderWindow& window) = 0;
	virtual void update(const sf::Time deltaTime, const sf::RenderWindow& window) {};
	virtual ~GameLevel() {};
};

