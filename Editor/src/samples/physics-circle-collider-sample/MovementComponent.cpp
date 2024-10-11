#include "MovementComponent.h"
#include <math/Vector3.h>
#include <scene/Transform.h>

using namespace Towell;

MovementComponent::MovementComponent(int updateOrder) : Component(updateOrder),
	speed(0.0f),
	direction(Vector2::Zero),
	velocity(Vector2::Zero)
{
}

void MovementComponent::Update(float deltaTime)
{
	if (Math::NearZero(velocity.x) && Math::NearZero(velocity.y))
	{
		return;
	}

	Vector3 position = gameObject->GetTransform()->GetPosition();
	position += Vector3(velocity.x, velocity.y, 0.0f) * deltaTime;
	gameObject->GetTransform()->SetPosition(position);
}

void MovementComponent::SetSpeed(float speed)
{
	this->speed = speed;

	velocity = this->direction * speed;
}

void MovementComponent::SetDirection(Vector2 direction)
{
	this->direction = Vector2::Normalize(direction);

	velocity = this->direction * speed;
}
