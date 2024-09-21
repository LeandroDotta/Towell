#ifndef TOWELL_SDL_WINDOW_H
#define TOWELL_SDL_WINDOW_H

#include "Window.h"

namespace Towell
{
	class SDLWindow : public Window
	{
	public:
		SDLWindow(std::string title, int width, int height);
		~SDLWindow();

		void Update() override;
		SDL_GLContext CreateOpenGLContext() override;

		int GetWidth() override;
		int GetHeight() override;
		void SetSize(int width, int height) override;
		std::string GetTitle() override;
		virtual void SetTitle(std::string title) override;

	private:
		int width;
		int height;
		SDL_Window* window;
	};
}

#endif // TOWELL_SDL_WINDOW_H