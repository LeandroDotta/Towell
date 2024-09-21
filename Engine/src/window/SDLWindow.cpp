#include "SDLWindow.h"
#include <Log.h>

using namespace Towell;

SDLWindow::SDLWindow(std::string title, int width, int height)
	: width(width), height(height)
{
	window = SDL_CreateWindow(title.c_str(), 50, 50, width, height, SDL_WINDOW_OPENGL);

	if (!window)
	{
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return;
	}
}

SDLWindow::~SDLWindow()
{
	if (!window)
	{
		return;
	}

	SDL_DestroyWindow(window);
}

void SDLWindow::Update()
{
	SDL_GL_SwapWindow(window);
}

SDL_GLContext SDLWindow::CreateOpenGLContext()
{
	return SDL_GL_CreateContext(window);
}

int SDLWindow::GetWidth()
{
	return width;
}

int SDLWindow::GetHeight()
{
	return height;
}

void SDLWindow::SetSize(int width, int height)
{
	this->width = width;
	this->height = height;
	SDL_SetWindowSize(window, width, height);
}

std::string SDLWindow::GetTitle()
{
	return std::string(SDL_GetWindowTitle(window));
}

void Towell::SDLWindow::SetTitle(std::string title)
{
	SDL_SetWindowTitle(window, title.c_str());
}