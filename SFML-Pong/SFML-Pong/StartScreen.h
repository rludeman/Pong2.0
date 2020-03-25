#pragma once
#include <SFML/Graphics.hpp>

#include "GameState.h"

class StartScreen
{
public:
	StartScreen(const sf::Font& font);
	~StartScreen();

	void handleEvents(const sf::Event& event, sf::RenderWindow& window, GameState& currentState);
	void draw(sf::RenderWindow& window);

private:
	struct Button {
		sf::RectangleShape box;
		sf::Text msg;
	};

	sf::Text title;
	Button playButton;
	Button quitButton;
};
