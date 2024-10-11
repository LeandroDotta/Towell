#ifndef TOWELL_APPLICATION_H
#define TOWELL_APPLICATION_H

#include <SDL.h>
#include <window/Window.h>
#include <rendering/Renderer.h>
#include <scene/Scene.h>
#include <scene/CircleCollider.h>
#include <asset/Assets.h>
#include <physics/Physics.h>

namespace Towell 
{
	class Application
	{
	public:
		Application();
		~Application();

		static Application* Init(std::string assetsFolder);
		static void Shutdown();

		void Run();

		static void AddGameObject(class GameObject* gameObject);
		static void SetBackgroundColor(Color color);

		void AddScene(class Scene* scene);
		void RemoveScene(class Scene* scene);


	private:
		bool running;
		Uint32 ticksCount;
		Renderer* renderer;
		Physics* physics;

		bool updatingGameObjects;
		std::vector<class GameObject*> gameObjects;
		std::vector<class GameObject*> pendingGameObjects;
		std::vector<class Scene*> scenes;

		void ProcessInput();
		void Update();
		void Render();

		void OnCollision(CircleCollider* colliderA, CircleCollider* colliderB, CollisionPhase phase, bool isTrigger, Vector3 normal, float depth);

		float CalculateDeltaTime();
	};
}

#endif // TOWELL_APPLICATION_H