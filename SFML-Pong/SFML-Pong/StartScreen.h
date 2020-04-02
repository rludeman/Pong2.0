#pragma once
#include <SFML/Graphics.hpp>

#include "GameLevel.h"


class StartScreen: public GameLevel
{
public:
	StartScreen();
	~StartScreen();

	virtual bool init(const sf::RenderWindow& window);

	virtual Levels handleEvents(const sf::Event& event, sf::RenderWindow& window);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

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
