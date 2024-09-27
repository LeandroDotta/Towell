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
		Scene(Application* app);
		~Scene();

		void Load(class Application* app);
		void Unload(class Application* app);

	protected:
		std::vector<class GameObject*> gameObjects;
	};
}

#endif // TOWELL_SCENE_H
