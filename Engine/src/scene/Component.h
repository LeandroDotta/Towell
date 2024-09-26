#ifndef TOWELL_COMPONENT_H
#define TOWELL_COMPONENT_H

#include "GameObject.h"

namespace Towell
{
	class Component
	{
	public:
		Component(int updateOrder = 0);
		virtual ~Component();

		virtual void Update(float deltaTime);

		int GetUpdateOrder() const { return updateOrder; }
		void SetGameObject(class GameObject* gameObject) { this->gameObject = gameObject; }
	protected:
		class GameObject* gameObject;
		int updateOrder;
	};
}

#endif // TOWELL_COMPONENT_H