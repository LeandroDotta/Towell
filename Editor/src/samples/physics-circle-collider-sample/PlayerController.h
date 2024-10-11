#ifndef TOWELL_EDITOR_PLAYER_CONTROLLER_H
#define TOWELL_EDITOR_PLAYER_CONTROLLER_H

#include "MovementComponent.h"
#include <scene/SpriteRenderer.h>

using namespace Towell;

class PlayerController : public MovementComponent
{
public:
	class Renderer2DComponent* renderer;

	PlayerController(int updateOrder = 0);

	void Update(float deltaTime) override;

private:
	void ClampPositionToScreen();
};

#endif // TOWELL_EDITOR_PLAYER_CONTROLLER_H