#pragma once
#include <SFML/Graphics.hpp>

#include "GameLevel.h"


class StartScreen: public GameLevel
{
public:
	StartScreen();
	~StartScreen();

	Levels handleEvents(const sf::Event& event, sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);

	void setFont(const sf::Font& font);

private:
	struct Button {
		sf::RectangleShape box;
		sf::Text msg;
	};

	sf::Text title;
	Button playButton;
	Button quitButton;
};
