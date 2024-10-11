#include "CollisionTester.h"
#include <Log.h>

#include "scene/CircleCollider.h"

CollisionTester::CollisionTester(ShapeRenderer* shape, int updateOrder) : Component(updateOrder), shape(shape)
{

}

void CollisionTester::OnCollisionEnter(CircleCollider* other, Vector3 normal, float depth)
{
	TW_INFO("Collision ENTER \t(%s <--> %s)", GetGameObject()->GetName().c_str(), other->GetGameObject()->GetName().c_str());
	TW_INFO("Other Collider Tag %s", other->GetGameObject()->GetTag().c_str());

	if (other->HasTag("Enemy"))
	{
		other->GetGameObject()->SetState(GameObject::State::Dead);
	}
}

void CollisionTester::OnCollisionStay(CircleCollider* other, Vector3 normal, float depth)
{
	TW_INFO("Collision STAY \t(%s <--> %s)", GetGameObject()->GetName().c_str(), other->GetGameObject()->GetName().c_str());
}

void CollisionTester::OnCollisionExit(CircleCollider* other, Vector3 normal, float depth)
{
	TW_INFO("Collision EXIT \t(%s <--> %s)", GetGameObject()->GetName().c_str(), other->GetGameObject()->GetName().c_str());
}

void CollisionTester::OnTriggerEnter(CircleCollider* other)
{
	TW_INFO("Trigger ENTER \t(%s <--> %s)", GetGameObject()->GetName().c_str(), other->GetGameObject()->GetName().c_str());
}

void CollisionTester::OnTriggerStay(CircleCollider* other)
{
	TW_INFO("Trigger STAY \t(%s <--> %s)", GetGameObject()->GetName().c_str(), other->GetGameObject()->GetName().c_str());
}

void CollisionTester::OnTriggerExit(CircleCollider* other)
{
	TW_INFO("Trigger EXIT \t(%s <--> %s)", GetGameObject()->GetName().c_str(), other->GetGameObject()->GetName().c_str());
}
