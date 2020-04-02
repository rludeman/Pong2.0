#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>


class Scoreboard: public sf::Drawable
{
public:
	Scoreboard();
	~Scoreboard();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	bool init();
	void incrementA();
	void incrementB();
	int getA() const;
	int getB() const;

private:
	void updateScore();

private:
	int scoreA;
	int scoreB;
	sf::Font font;
	sf::Text scoreboard;
};

