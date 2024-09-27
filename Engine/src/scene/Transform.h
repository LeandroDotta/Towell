#ifndef TOWELL_TRANSFORM_H
#define TOWELL_TRANSFORM_H

#include "Component.h"
#include <math/Vector3.h>
#include <math/Matrix4.h>

namespace Towell
{
	class Transform : public Component
	{
	public:
		Transform();

		void Update(float deltaTime) override;

		void ComputeWorldTransform();
		const Matrix4& GetWorldTransform() const { return worldTransform; }

		Vector3 GetPosition() const { return position; }
		void SetPosition(Vector3 position) 
		{ 
			this->position = position;
			shouldRecomputeWorldTransform = true;
		}
		Vector3 GetScale() const { return scale; }
		void SetScale(Vector3 scale) 
		{ 
			this->scale = scale; 
			shouldRecomputeWorldTransform = true;
		}
		Vector3 GetRotation() const { return rotation; }
		void SetRotation(Vector3 rotation)
		{
			this->rotation = rotation;
			shouldRecomputeWorldTransform = true;
		}
	private:
		Vector3 position;
		Vector3 scale;
		Vector3 rotation;

		Matrix4 worldTransform;
		bool shouldRecomputeWorldTransform;
	};
}
#endif // TOWELL_TRANSFORM_H

