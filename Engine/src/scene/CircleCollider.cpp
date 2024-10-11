#include "CircleCollider.h"

#include "Transform.h"

using namespace Towell;

CircleCollider::CircleCollider(int updateOrder) 
	: Component(updateOrder), radius(0.0f), trigger(false)
{
}

float CircleCollider::GetRadius() const
{
	return radius * gameObject->GetTransform()->GetScale().x;
}

const Vector3& CircleCollider::GetCenter() const
{
	return gameObject->GetTransform()->GetPosition();
}


