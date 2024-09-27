#include "Transform.h"

using namespace Towell;

Transform::Transform() : 
	scale(Vector3(1.0f, 1.0f, 1.0f)),
	shouldRecomputeWorldTransform(true)
{
}

void Transform::Update(float deltaTime)
{
	ComputeWorldTransform();
}

void Transform::ComputeWorldTransform()
{
	if (!shouldRecomputeWorldTransform)
	{
		return;
	}

	shouldRecomputeWorldTransform = false;
	
	// Scale, then rotate, then translate
	worldTransform = Matrix4::CreateScale(scale);
	worldTransform *= Matrix4::CreateRotationZ(rotation.z);
	worldTransform *= Matrix4::CreateTranslation(position);
}
