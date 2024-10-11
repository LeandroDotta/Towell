#ifndef TOWELL_CIRCLE_COLLIDER_H
#define TOWELL_CIRCLE_COLLIDER_H

#include "Component.h"
#include <math/Vector3.h>

namespace Towell
{
	class CircleCollider : public Component
	{
	public:
		CircleCollider(int updateOrder = 0);

		float GetRadius() const;
		void SetRadius(float radius) { this->radius = radius; }
		bool IsTrigger() const { return trigger; }
		void SetTrigger(bool isTrigger) { this->trigger = isTrigger; }

		const Vector3& GetCenter() const;

	private:
		float radius;
		bool trigger;
	};
}

#endif // TOWELL_CIRCLE_COLLIDER_H

