#include "PlayerController.h"
#include "input/Input.h"
#include "input/KeyCode.h"
#include <math/Vector2.h>
#include <math/Vector3.h>
#include <scene/Transform.h>
#include <window/Screen.h>

using namespace Towell;

PlayerController::PlayerController(int updateOrder) : MovementComponent(updateOrder),
	renderer(nullptr)
{
}

void PlayerController::Update(float deltaTime)
{
	Vector2 direction = Vector2::Zero;
	
	if (Input::IsKeyPressed(Input::KeyCode::W) || Input::IsKeyPressed(Input::KeyCode::UpArrow))
	{
		direction.y += 1.0f;
	}
	if (Input::IsKeyPressed(Input::KeyCode::S) || Input::IsKeyPressed(Input::KeyCode::DownArrow))
	{
		direction.y -= 1.0f;
	}
	if (Input::IsKeyPressed(Input::KeyCode::D) || Input::IsKeyPressed(Input::KeyCode::RightArrow))
	{
		direction.x += 1.0f;
	}
	if (Input::IsKeyPressed(Input::KeyCode::A) || Input::IsKeyPressed(Input::KeyCode::LeftArrow))
	{
		direction.x -= 1.0f;
	}

	SetDirection(direction);
	MovementComponent::Update(deltaTime);
}
