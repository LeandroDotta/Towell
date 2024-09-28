#ifndef TOWELL_APPLICATION_H
#define TOWELL_APPLICATION_H

#include <SDL.h>
#include <window/Window.h>
#include <rendering/Renderer.h>
#include <scene/Scene.h>
#include <asset/Assets.h>

namespace Towell 
{
	class Application
	{
	public:
		Application();
		~Application();

		bool Init(std::string assetsFolder);
		void Run();

		void AddGameObject(class GameObject* gameObject);
		void RemoveGameObject(class GameObject* gameObject);
		void AddScene(class Scene* scene);
		void RemoveScene(class Scene* scene);
	private:
		bool running;
		Uint32 ticksCount;
		Renderer* renderer;

		bool updatingGameObjects;
		std::vector<class GameObject*> gameObjects;
		std::vector<class GameObject*> pendingGameObjects;
		std::vector<class Scene*> scenes;

		void ProcessInput();
		void Update();
		void Render();

		float CalculateDeltaTime();
	};
}

#endif // TOWELL_APPLICATION_H