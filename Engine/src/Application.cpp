#include "Application.h"

#include <SDL.h>
#include "GL/glew.h"
#include "window/SDLWindow.h"

using namespace Towell;

Application::Application() : window(nullptr), running(true) { }

Application::~Application() 
{
	SDL_GL_DeleteContext(context);
	delete window;
	SDL_Quit();
}

bool Application::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}

	// Setup OpenGL attributes
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

	// Create the window
	window = new SDLWindow("Towell Engine", 1024, 786);
	context = window->CreateOpenGLContext();

	// Initialize GLEW
	glewExperimental = GL_TRUE;
	int glewStatus = glewInit();
	if (glewStatus != GLEW_OK)
	{
		SDL_Log("Failed to initialize GLEW with status %d.", glewStatus);
		return false;
	}

	// On some platforms, GLEW will emit a benign error code, so clear it
	glGetError();

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
	// TODO: Process Input
}

void Application::Update()
{
	// TODO: Implement Game Lopp
}

void Application::Render()
{
	glClearColor(0.86f, 0.86f, 0.86f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	window->Update();
}