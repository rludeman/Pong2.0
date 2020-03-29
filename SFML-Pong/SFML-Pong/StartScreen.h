#pragma once
#include <SFML/Graphics.hpp>

#include "GameLevel.h"


class StartScreen: public GameLevel
{
public:
	StartScreen();
	~StartScreen();

	bool init();

	Levels handleEvents(const sf::Event& event, sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);

private:
	struct Button {
		sf::RectangleShape box;
		sf::Text msg;
	};

	sf::Font font;
	sf::Text title;
	Button playButton;
	Button quitButton;
};
