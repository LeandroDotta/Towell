#ifndef TOWELL_SCENE_H
#define TOWELL_SCENE_H

#include <vector>
#include "GameObject.h"
#include "Application.h"

namespace Towell
{
	class Scene
	{
	public:
		Scene();
		~Scene();

		void Load(class Application* app);
		void Unload(class Application* app);

	protected:
		std::vector<class GameObject*> gameObjects;

		void AddGameObject(class GameObject* gameObject);
		void RemoveGameObject(class GameObject* gameObject);
	};
}

#endif // TOWELL_SCENE_H

