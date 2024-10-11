#ifndef TOWELL_COMPONENT_H
#define TOWELL_COMPONENT_H

#include "GameObject.h"
#include "math/Vector3.h"

namespace Towell
{
	class Component
	{
	public:
		Component(int updateOrder = 0);
		virtual ~Component();

		virtual void Update(float deltaTime);

		virtual void OnCollisionEnter(class CircleCollider* other, Vector3 normal, float depth) {}
		virtual void OnCollisionStay(class CircleCollider* other, Vector3 normal, float depth) {}
		virtual void OnCollisionExit(class CircleCollider* other, Vector3 normal, float depth) {}
		virtual void OnTriggerEnter(class CircleCollider* other) {}
		virtual void OnTriggerStay(class CircleCollider* other) {}
		virtual void OnTriggerExit(class CircleCollider* other) {}

		int GetUpdateOrder() const { return updateOrder; }
		GameObject* GetGameObject() const { return gameObject; }
		void SetGameObject(class GameObject* gameObject) { this->gameObject = gameObject; }
	protected:
		class GameObject* gameObject;
		int updateOrder;
	};
}

#endif // TOWELL_COMPONENT_H