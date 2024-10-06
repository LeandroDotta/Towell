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

	CreateShapeAtPosition(Vector3(-300.0f, -300.0f, 0.0f), ShapeRenderer::Shape::Triangle, Color::Red);
	CreateShapeAtPosition(Vector3(400.0f, -300.0f, 0.0f), ShapeRenderer::Shape::Triangle, Color::Blue);
	CreateShapeAtPosition(Vector3(-400.0f, 300.0f, 0.0f), ShapeRenderer::Shape::Quad, Color::Green);
	CreateShapeAtPosition(Vector3(400.0f, -100.0f, 0.0f), ShapeRenderer::Shape::Circle, Color::Black);
	CreateShapeAtPosition(Vector3(0.0f, 300.0f, 0.0f), ShapeRenderer::Shape::Circle, Color::Red);
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

void SampleScene::CreateShapeAtPosition(Vector3 position, ShapeRenderer::Shape type, Color color)
{
	ShapeRenderer* shape = new ShapeRenderer(type, 50.0f, 50.0f, color);

	GameObject* shapeObject = new GameObject("Shape");
	shapeObject->AddComponent(shape);
	shapeObject->GetTransform()->SetPosition(position);

	gameObjects.emplace_back(shapeObject);
}
