#include "GameObject.h"
#include "Component.h"
#include "Transform.h"

using namespace Towell;

GameObject::GameObject(std::string name, Application* app) : name(name), app(app), state(Active)
{
	transform = new Transform();
	AddComponent(transform);
}

GameObject::~GameObject()
{
	while (!components.empty())
	{
		delete components.back();
	}

	delete transform;
}

void GameObject::Update(float deltaTime)
{
	if (state != Active)
	{
		return;
	}

	for (Component* component : components)
	{
		component->Update(deltaTime);
	}
}

void GameObject::AddComponent(Component* component)
{
	int order = component->GetUpdateOrder();

	auto iterator = components.begin();
	for (; iterator != components.end(); ++iterator)
	{
		if (order < (*iterator)->GetUpdateOrder())
		{
			break;
		}
	}

	component->SetGameObject(this);
	components.insert(iterator, component);
}

void GameObject::RemoveComponent(Component* component)
{
	auto iterator = std::find(components.begin(), components.end(), component);

	if (iterator != components.end())
	{
		components.erase(iterator);
	}

	component->SetGameObject(nullptr);
}

Transform* GameObject::GetTransform()
{
	return transform;
}
