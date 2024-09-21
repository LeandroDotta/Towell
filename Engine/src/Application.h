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
		bool running;
		Uint32 ticksCount;
		Window* window;
		SDL_GLContext context;

		void ProcessInput();
		void Update();
		void Render();

		float CalculateDeltaTime();
	};
}

#endif // TOWELL_APPLICATION_H