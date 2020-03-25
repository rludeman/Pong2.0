#include "AIController.h"


AIController::AIController()
{
}

AIController::~AIController()
{
}

void AIController::setPaddle(Paddle * ptr) { paddlePtr = ptr; }

void AIController::udpate(const Ball & ball) // Improve AI Controller
{
	float paddleCenter = paddlePtr->getPosition().y + paddlePtr->getSize().y / 2.f;
	if (paddleCenter < ball.getPosition().y)
		paddlePtr->moveDown();
	if (paddleCenter > ball.getPosition().y)
		paddlePtr->moveUp();

}
