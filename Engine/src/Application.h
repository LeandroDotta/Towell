#ifndef TOWELL_APPLICATION_H
#define TOWELL_APPLICATION_H

#include <SDL.h>
#include "window/Window.h"

namespace Towell 
{
	class Application
	{
	public:
		Application();
		~Application();

		bool Init();

		void Run();


	private:
		void ProcessInput();
		void Update();
		void Render();

		bool running;
		Window* window;
		SDL_GLContext context;
	};
}

#endif // TOWELL_APPLICATION_H