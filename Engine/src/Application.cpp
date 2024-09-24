#include "Application.h"

#include <SDL.h>
#include "GL/glew.h"
#include "window/SDLWindow.h"
#include <Towell.h>

using namespace Towell;

Application::Application() : 
	running(true), 
	renderer(nullptr), 
	ticksCount(0.0f) { }

Application::~Application() 
{
	delete renderer;
}

bool Application::Init()
{
	renderer = new Renderer();
	renderer->Init();

	ticksCount = SDL_GetTicks();

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

	// TODO: Update GameObjects and Components
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