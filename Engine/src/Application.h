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

		void AddGameObject(class GameObject* gameObject);
		void RemoveGameObject(class GameObject* gameObject);

	private:
		bool running;
		Uint32 ticksCount;
		Renderer* renderer;

		bool updatingGameObjects;
		std::vector<class GameObject*> gameObjects;
		std::vector<class GameObject*> pendingGameObjects;

		void ProcessInput();
		void Update();
		void Render();

		float CalculateDeltaTime();
	};
}

#endif // TOWELL_APPLICATION_H