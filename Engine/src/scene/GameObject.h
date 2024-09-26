#ifndef TOWELL_GAME_OBJECT_H
#define TOWELL_GAME_OBJECT_H

#include <vector>
#include <string>

namespace Towell
{
	class GameObject
	{
	public:
		enum State
		{
			Active,
			Paused,
			Dead
		};

		GameObject(std::string name, class Application* app);
		~GameObject();

		void Update(float deltaTime);

		void AddComponent(class Component* component);
		void RemoveComponent(class Component* component);

		State GetState() const { return state; }
		void SetState(State state) { this->state = state; }
		
		std::string GetName() const { return name; }
		void SetName(std::string name) { this->name = name; }

		class Transform* GetTransform();

	private:
		State state;
		std::string name;

		class Transform* transform;
		class Application* app;

		std::vector<class Component*> components;
	};
}

#endif // TOWELL_GAME_OBJECT_H