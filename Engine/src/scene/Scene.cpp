#include "Scene.h"

using namespace Towell;

Scene::Scene()
{
}

Scene::~Scene()
{
	while (!gameObjects.empty())
	{
		delete gameObjects.back();
		gameObjects.pop_back();
	}
}

void Scene::Load(class Application* app)
{
	for (auto gameObject : gameObjects)
	{
		app->AddGameObject(gameObject);
	}
}

void Scene::Unload(class Application* app)
{
	for (auto gameObject : gameObjects)
	{
		gameObject->SetState(GameObject::Dead);
	}
}

void Scene::AddGameObject(GameObject* gameObject)
{
	gameObjects.emplace_back(gameObject);
}

void Scene::RemoveGameObject(GameObject* gameObject)
{
	auto iterator = std::find(gameObjects.begin(), gameObjects.end(), gameObject);

	if (iterator != gameObjects.end())
	{
		gameObjects.erase(iterator);
	}
}
