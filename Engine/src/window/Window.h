#ifndef TOWELL_WINDOW_H
#define TOWELL_WINDOW_H

#include <SDL.h>
#include <string>

namespace Towell
{
	class Window
	{
	public:
		virtual void Update() = 0;

		// TODO: Detach the context creation or make ir more generic to not dependo on SDL
		virtual SDL_GLContext CreateOpenGLContext() = 0;

		// Getters & Setters
		virtual int GetWidth() = 0;
		virtual int GetHeight() = 0;
		virtual void SetSize(int width, int height) = 0;
		virtual std::string GetTitle() = 0;
		virtual void SetTitle(std::string title) = 0;
	};
}

#endif // TOWELL_WINDOW_H

