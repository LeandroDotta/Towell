#include "CircleColliderScene.h"

#include <scene/GameObject.h>
#include <scene/Transform.h>
#include <scene/ShapeRenderer.h>
#include "MovementComponent.h"
#include "PlayerController.h"
#include "CollisionTester.h"

using namespace Towell;

CircleColliderScene::CircleColliderScene()
{
	CreatePlayerCircle();

	// Trigger Circles
	CreateCircleAt("Circle 1", Vector3(-50.0f, 100.0f, 0.0f), Color::Parse("EF476F"), true);
	CreateCircleAt("Circle 2", Vector3(250.0f, 150.0f, 0.0f), Color::Parse("FFD166"), true);
	CreateCircleAt("Circle 3",Vector3(-375.0f, 0.0f, 0.0f), Color::Parse("8AC926"), true);

	// Collision Circles
	CreateCircleAt("Circle 4",Vector3(-250.0f, 79.0f, 0.0f), Color::Parse("1982C4"), false, "Enemy");
	CreateCircleAt("Circle 5",Vector3(-300.0f, -215.0f, 0.0f), Color::Parse("6A4C93"), false, "Enemy");
	CreateCircleAt("Circle 6",Vector3(-325.0f, -147.0f, 0.0f), Color::Parse("FF595E"), false, "Enemy");
	CreateCircleAt("Circle 7",Vector3(-50.0f, -129.0f, 0.0f), Color::Parse("06D6A0"));
	CreateCircleAt("Circle 8",Vector3(-175.0f, -100.0f, .0f), Color::Parse("F9844A"));
	CreateCircleAt("Circle 9",Vector3(150.0f, 150.0f, .0f), Color::Parse("ff006e"));
	CreateCircleAt("Circle 10",Vector3(390.0f, 300.0f, .0f), Color::Parse("f48c06"));
	CreateCircleAt("Circle 11",Vector3(100.0f, -275.0f, .0f), Color::Parse("9e0059"));
	CreateCircleAt("Circle 12",Vector3(179.0f, -100.0f, .0f), Color::Parse("9d4edd"));
	CreateCircleAt("Circle 13",Vector3(300.0f, -350.0f, .0f), Color::Parse("34a0a4"));
}

void CircleColliderScene::CreatePlayerCircle()
{
	GameObject* player = new GameObject("Player");
	
	ShapeRenderer* circle = new ShapeRenderer(ShapeRenderer::Shape::Circle, 50.0f, 50.0f, Color::White);
	CollisionTester* collisionTester = new CollisionTester(circle);
	
	CircleCollider* collider = new CircleCollider();
	collider->SetRadius(25.0f);
	
	PlayerController* playerController = new PlayerController();
	playerController->SetSpeed(300.0f);
	playerController->renderer = circle;
	
	player->AddComponent(circle);
	player->AddComponent(collisionTester);
	player->AddComponent(playerController);
	player->AddComponent(collider);
	
	player->GetTransform()->SetPosition(Vector3::Zero);
	
	gameObjects.emplace_back(player);
}

void CircleColliderScene::CreateCircleAt(char* name, Vector3 position, Color color, bool isTrigger, char* tag)
{
	ShapeRenderer* shape = new ShapeRenderer(ShapeRenderer::Shape::Circle, 50.0f, 50.0f, color);
	
	CircleCollider* collider = new CircleCollider();
	collider->SetRadius(25.0f);
	collider->SetTrigger(isTrigger);

	GameObject* circle = new GameObject(name);
	circle->AddComponent(shape);
	circle->AddComponent(collider);
	circle->GetTransform()->SetPosition(position);

	if (tag)
	{
		circle->SetTag(tag);
	}

	gameObjects.emplace_back(circle);
}
