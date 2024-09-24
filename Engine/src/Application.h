#ifndef TOWELL_APPLICATION_H
#define TOWELL_APPLICATION_H

#include <SDL.h>
#include "window/Window.h"
#include "rendering/Renderer.h"

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
		Renderer* renderer;

		void ProcessInput();
		void Update();
		void Render();

		float CalculateDeltaTime();
	};
}

#endif // TOWELL_APPLICATION_H