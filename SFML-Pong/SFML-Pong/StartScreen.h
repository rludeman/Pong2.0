#pragma once
#include <SFML/Graphics.hpp>

#include "GameState.h"


class StartScreen
{
public:
	StartScreen();
	~StartScreen();

	void setFont(const sf::Font& font);
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
