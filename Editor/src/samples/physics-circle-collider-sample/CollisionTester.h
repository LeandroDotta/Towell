#ifndef TOWELL_EDITOR_COLOR_CHANGER
#define TOWELL_EDITOR_COLOR_CHANGER

#include "scene/Component.h"
#include "scene/ShapeRenderer.h"
#include "math/Vector3.h"

using namespace Towell;

class CollisionTester : public Component 
{
public:
	CollisionTester(ShapeRenderer* shape, int updateOrder = 0);

	void OnCollisionEnter(class CircleCollider* other, Vector3 normal, float depth) override;
	void OnCollisionStay(class CircleCollider* other, Vector3 normal, float depth) override;
	void OnCollisionExit(class CircleCollider* other, Vector3 normal, float depth) override;
	void OnTriggerEnter(class CircleCollider* other) override;
	void OnTriggerStay(class CircleCollider* other) override;
	void OnTriggerExit(class CircleCollider* other) override;

private:
	ShapeRenderer* shape;
};

#endif // !TOWELL_EDITOR_COLOR_CHANGER
