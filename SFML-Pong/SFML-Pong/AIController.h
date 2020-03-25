#pragma once
#include <SFML/Graphics.hpp>

#include "Paddle.h"
#include "Ball.h"

class AIController
{
public:
	AIController();
	~AIController();

	void setPaddle(Paddle* ptr);

	void udpate(const Ball& ball);

private:
	Paddle* paddlePtr;
};

