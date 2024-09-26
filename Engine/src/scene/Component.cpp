#include "Component.h"

using namespace Towell;
Component::Component(int updateOrder) : 
	gameObject(nullptr),
	updateOrder(updateOrder)
{
}

Component::~Component()
{
	if (!gameObject)
	{
		return;
	}

	gameObject->RemoveComponent(this);
}

void Component::Update(float deltaTime)
{
}
