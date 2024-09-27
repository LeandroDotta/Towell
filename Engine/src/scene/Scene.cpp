#include "Scene.h"

using namespace Towell;

Scene::Scene(Application* app)
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
		app->RemoveGameObject(gameObject);
	}
}