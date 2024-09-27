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
	while (!gameObjects.empty())
	{
		gameObjects.pop_back();
	}

	delete textureSpaceship;
	delete renderer;
}

bool Application::Init()
{
	renderer = new Renderer();
	renderer->Init();

	ticksCount = SDL_GetTicks();

	textureSpaceship = new Texture();
	textureSpaceship->Load("../Game/Assets/spaceship.png");

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

	for (auto sprite : gameObject->GetComponents<SpriteRenderer>())
	{
		renderer->AddSprite(sprite);
	}
}

void Application::RemoveGameObject(GameObject* gameObject)
{
	// Remove from pending game objects list
	auto iterator = std::find(pendingGameObjects.begin(), pendingGameObjects.end(), gameObject);

	if (iterator != pendingGameObjects.end())
	{
		std::iter_swap(iterator, pendingGameObjects.end() - 1);
		
		GameObject* gameObjectToRemove = pendingGameObjects.back();
		for (auto sprite : gameObjectToRemove->GetComponents<SpriteRenderer>())
		{
			renderer->RemoveSprite(sprite);
		}

		pendingGameObjects.pop_back();
	}

	// Remove from main game objects list
	iterator = std::find(gameObjects.begin(), gameObjects.end(), gameObject);

	if (iterator != gameObjects.end())
	{
		std::iter_swap(iterator, gameObjects.end() - 1);

		GameObject* gameObjectToRemove = gameObjects.back();
		for (auto sprite : gameObjectToRemove->GetComponents<SpriteRenderer>())
		{
			renderer->RemoveSprite(sprite);
		}

		gameObjects.pop_back();
	}
}

void Application::AddScene(Scene* scene)
{
	scene->Load(this);
	scenes.emplace_back(scene);
}

void Application::RemoveScene(Scene* scene)
{
	scene->Unload(this);

	auto iterator = std::find(scenes.begin(), scenes.end(), scene);

	if (iterator != scenes.end())
	{
		std::iter_swap(iterator, scenes.end() - 1);
		scenes.pop_back();
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