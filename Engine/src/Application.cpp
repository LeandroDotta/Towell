#include "Application.h"

#include <algorithm>
#include <SDL.h>
#include "GL/glew.h"
#include "window/SDLWindow.h"
#include <Towell.h>
#include <scene/Transform.h>
#include <input/Input.h>
#include <window/Screen.h>

using namespace Towell;

static Application* app;

Application::Application() : 
	running(true), 
	updatingGameObjects(false),
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

	Assets::Shutdown();
	Screen::Shutdown();
	
	if (renderer)
	{
		delete renderer;
	}

	Input::Shutdown();
}

Application* Application::Init(std::string assetsFolder)
{
	app = new Application();

	Input::Init();

	app->renderer = new Renderer();
	if (!app->renderer->Init())
	{
		TW_ERROR("Failed to initialize Renderer");
		app->renderer = nullptr;
		return nullptr;
	}

	Screen::Init(app->renderer->GetWindow());
	Assets::Init(assetsFolder);

	app->physics = new Physics();
	app->physics->SetCollisionCallback([](CircleCollider* colliderA, CircleCollider* colliderB, CollisionPhase phase, bool isTrigger, Vector3 normal, float depth) {
		app->OnCollision(colliderA, colliderB, phase, isTrigger, normal, depth);
	});

	app->ticksCount = SDL_GetTicks();

	return app;
}

void Application::Shutdown()
{
	delete app;
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
	if (app->updatingGameObjects)
	{
		app->pendingGameObjects.emplace_back(gameObject);
	}
	else
	{
		app->gameObjects.emplace_back(gameObject);
	}

	for (auto sprite : gameObject->GetComponents<SpriteRenderer>())
	{
		app->renderer->AddSprite(sprite);
	}

	for (auto shape : gameObject->GetComponents<ShapeRenderer>())
	{
		app->renderer->AddShape(shape);
	}

	for (auto collider : gameObject->GetComponents<CircleCollider>())
	{
		app->physics->AddCollider(collider);
	}
}

void Application::SetBackgroundColor(Color color)
{
	app->renderer->SetBackgroundColor(color);
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
	Input::GetInstance()->Update();

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

	if (Input::IsKeyPressed(Input::KeyCode::Escape))
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
		pending->GetTransform()->ComputeWorldTransform();
		gameObjects.emplace_back(pending);
	}
	pendingGameObjects.clear();


	// Remove all dead Game Objects
	for (auto iterator = gameObjects.begin(); iterator != gameObjects.end(); )
	{
		if ((*iterator)->GetState() == GameObject::Dead)
		{
			for (auto sprite : (*iterator)->GetComponents<SpriteRenderer>())
			{
				app->renderer->RemoveSprite(sprite);
			}

			for (auto shape : (*iterator)->GetComponents<ShapeRenderer>())
			{
				app->renderer->RemoveShape(shape);
			}

			for (auto collider : (*iterator)->GetComponents<CircleCollider>())
			{
				app->physics->RemoveCollider(collider);
			}

			iterator = gameObjects.erase(iterator);
		}
		else
		{
			++iterator;
		}
	}

	physics->Update();
}

void Application::Render()
{
	renderer->RenderFrame();
}

void Application::OnCollision(CircleCollider* colliderA, CircleCollider* colliderB, CollisionPhase phase, bool isTrigger, Vector3 normal, float depth)
{
	for (auto component : colliderA->GetGameObject()->GetAllComponents())
	{
		if (isTrigger)
		{
			if (phase == CollisionPhase::Enter)
			{
				component->OnTriggerEnter(colliderB);
				component->OnTriggerStay(colliderB);
			}
			else if (phase == CollisionPhase::Stay)
			{
				component->OnTriggerStay(colliderB);
			}
			else if (phase == CollisionPhase::Exit)
			{
				component->OnTriggerExit(colliderB);
			}
		}
		else
		{
			if (phase == CollisionPhase::Enter)
			{
				component->OnCollisionEnter(colliderB, normal, depth);
				component->OnCollisionStay(colliderB, normal, depth);
			}
			else if (phase == CollisionPhase::Stay)
			{
				component->OnCollisionStay(colliderB, normal, depth);
			}
			else if (phase == CollisionPhase::Exit)
			{
				component->OnCollisionExit(colliderB, normal, depth);
			}
		}
	}

	for (auto component : colliderB->GetGameObject()->GetAllComponents())
	{
		if (isTrigger)
		{
			if (phase == CollisionPhase::Enter)
			{
				component->OnTriggerEnter(colliderA);
				component->OnTriggerStay(colliderA);
			}
			else if (phase == CollisionPhase::Stay)
			{
				component->OnTriggerStay(colliderA);
			}
			else if (phase == CollisionPhase::Exit)
			{
				component->OnTriggerExit(colliderA);
			}
		}
		else
		{
			if (phase == CollisionPhase::Enter)
			{
				component->OnCollisionEnter(colliderA, normal, depth);
				component->OnCollisionStay(colliderA, normal, depth);
			}
			else if (phase == CollisionPhase::Stay)
			{
				component->OnCollisionStay(colliderA, normal, depth);
			}
			else if (phase == CollisionPhase::Exit)
			{
				component->OnCollisionExit(colliderA, normal, depth);
			}
		}
	}
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