#pragma once

#include "GameLevel.h"
#include "Ball.h"
#include "Paddle.h"
#include "AIController.h"
#include "Scoreboard.h"


class PongGame: public GameLevel
{
public:
	PongGame();
	~PongGame();

	// Game loop methods
	virtual Levels handleEvents(const sf::Event& event, sf::RenderWindow& window);
	virtual void update(const sf::Time deltaTime, const sf::RenderWindow& window);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	// Helper methods for game
	virtual bool init(const sf::RenderWindow& window);
	void reset(const sf::RenderWindow& window);
	bool checkScore(const Ball& ball, const sf::RenderWindow& window);

private:
	sf::Font font;
	AIController ai;
	Scoreboard scoreboard;
	sf::Text winMsg;	
	sf::Text loseMsg;
	Ball ball;
	Paddle paddleA;
	Paddle paddleB;

	// TODO add background image
	// TODO add audio assets
};
