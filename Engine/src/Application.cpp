#include "Application.h"

#include <algorithm>
#include <SDL.h>
#include "GL/glew.h"
#include "window/SDLWindow.h"
#include <Towell.h>
#include <scene/Transform.h>

using namespace Towell;

Application::Application() : 
	running(true), 
	renderer(nullptr), 
	ticksCount(0.0f) 
{
	
}

Application::~Application() 
{
	delete renderer;
}

bool Application::Init()
{
	renderer = new Renderer();
	renderer->Init();

	ticksCount = SDL_GetTicks();

	Texture* texture = new Texture();
	texture->Load("../Game/Assets/spaceship.png");

	SpriteRenderer* sprite = new SpriteRenderer();
	sprite->SetTexture(texture);

	GameObject* ship = new GameObject("Player", this);
	ship->AddComponent(sprite);
	ship->GetTransform()->SetPosition(Vector3(-50.0f, 10.0f, 0.0f));

	SpriteRenderer* sprite2 = new SpriteRenderer();
	sprite2->SetTexture(texture);

	GameObject* ship2 = new GameObject("Spaceship", this);
	ship2->AddComponent(sprite2);
	ship2->GetTransform()->SetPosition(Vector3(50.0f, 0.0f, 0.0f));

	AddGameObject(ship);
	AddGameObject(ship2);
	
	renderer->AddSprite(sprite);
	renderer->AddSprite(sprite2);

	return true;
}

void Application::Run()
{
	while (running)
	{
		ProcessInput();
		Update();
		Render();
	}
}

void Application::AddGameObject(GameObject* gameObject)
{
	if (updatingGameObjects)
	{
		pendingGameObjects.emplace_back(gameObject);
	}
	else
	{
		gameObjects.emplace_back(gameObject);
	}
}

void Application::RemoveGameObject(GameObject* gameObject)
{
	// Remove from pending game objects list
	auto iterator = std::find(pendingGameObjects.begin(), pendingGameObjects.end(), gameObject);

	if (iterator != pendingGameObjects.end())
	{
		std::iter_swap(iterator, pendingGameObjects.end() - 1);
		pendingGameObjects.pop_back();
	}

	// Remove from main game objects list
	iterator = std::find(gameObjects.begin(), gameObjects.end(), gameObject);

	if (iterator != gameObjects.end())
	{
		std::iter_swap(iterator, gameObjects.end() - 1);
		gameObjects.pop_back();
	}
}

void Application::ProcessInput()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			running = false;
			break;
		}
	}

	const Uint8* keyState = SDL_GetKeyboardState(NULL);
	if (keyState[SDL_SCANCODE_ESCAPE])
	{
		running = false;
	}
}

void Application::Update()
{
	float deltaTime = CalculateDeltaTime();

	// Update Game Objects
	updatingGameObjects = true;
	for (auto gameObject : gameObjects)
	{
		if (gameObject->GetState() == GameObject::Active)
		{
			gameObject->Update(deltaTime);
		}
	}
	updatingGameObjects = false;


	for (auto pending : pendingGameObjects)
	{
		gameObjects.emplace_back(pending);
	}
	pendingGameObjects.clear();
}

void Application::Render()
{
	renderer->RenderFrame();
}

float Application::CalculateDeltaTime()
{
	// Wait until 16ms has elapsed since last frame
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksCount + 16));

	float deltaTime = (SDL_GetTicks() - ticksCount) / 1000.0f;

	// Clamps the delta time to avoid long times 
	// when the application is paused (in debbuging, for example)
	if (deltaTime > 0.05f)
	{
		deltaTime = 0.05f;
	}

	ticksCount = SDL_GetTicks();

	return deltaTime;
}