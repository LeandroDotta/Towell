#include "SampleScene.h"
#include <Application.h>
#include <scene/SpriteRenderer.h>
#include <scene/Transform.h>

SampleScene::SampleScene(Application* app) : Scene(app)
{
	CreateSpaceshipAtPosition(Vector3::Zero, app);
	CreateSpaceshipAtPosition(Vector3(50.0f, 30.0f, 0.0f), app);
	CreateSpaceshipAtPosition(Vector3(-50.0f, -30.0f, 0.0f), app);
	CreateSpaceshipAtPosition(Vector3(250.0f, -100.0f, 0.0f), app);
}

void SampleScene::CreateSpaceshipAtPosition(Vector3 position, Application* app)
{
	Texture* texture = app->GetTexture();

	SpriteRenderer* sprite = new SpriteRenderer();
	sprite->SetTexture(texture);

	GameObject* ship = new GameObject("Ship", app);
	ship->AddComponent(sprite);
	ship->GetTransform()->SetPosition(position);

	gameObjects.emplace_back(ship);
}
