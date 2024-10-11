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

		GameObject(std::string name);
		~GameObject();

		void Update(float deltaTime);

		void AddComponent(class Component* component);
		void RemoveComponent(class Component* component);

		template <typename T>
		std::vector<T*> GetComponents();
		std::vector<class Component*> GetAllComponents() const { return components; }

		State GetState() const { return state; }
		void SetState(State state) { this->state = state; }
		
		std::string GetName() const { return name; }
		void SetName(std::string name) { this->name = name; }

		class Transform* GetTransform();

	private:
		State state;
		std::string name;

		class Transform* transform;

		std::vector<class Component*> components;
	};


	template<typename T>
	inline std::vector<T*> GameObject::GetComponents()
	{
		static_assert(std::is_base_of<Component, T>::value, "T is not of type Component");

		std::vector<T*> result;
		
		for (Component* component : components)
		{
			T* typeComp = dynamic_cast<T*>(component);
			if (typeComp)
			{
				result.push_back(typeComp);
			}
		}

		return result;
	}
}

#endif // TOWELL_GAME_OBJECT_H