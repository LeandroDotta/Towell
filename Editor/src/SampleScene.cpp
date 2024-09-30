#include "SampleScene.h"
#include <Application.h>
#include <scene/SpriteRenderer.h>
#include <scene/Transform.h>

SampleScene::SampleScene() : Scene()
{
	CreateSpaceshipAtPosition(Vector3::Zero);
	CreateSpaceshipAtPosition(Vector3(50.0f, 30.0f, 0.0f));
	CreateSpaceshipAtPosition(Vector3(-50.0f, -30.0f, 0.0f));
	CreateSpaceshipAtPosition(Vector3(250.0f, -100.0f, 0.0f));
}

void SampleScene::CreateSpaceshipAtPosition(Vector3 position)
{
	Texture* texture = Assets::GetTexture("spaceship.png");

	SpriteRenderer* sprite = new SpriteRenderer();
	sprite->SetTexture(texture);

	GameObject* ship = new GameObject("Ship");
	ship->AddComponent(sprite);
	ship->GetTransform()->SetPosition(position);

	gameObjects.emplace_back(ship);
}
