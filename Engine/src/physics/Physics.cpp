#include "Physics.h"
#include "scene/Transform.h"

using namespace Towell;

Physics::Physics() : collisionCallback(nullptr)
{
}

Physics::~Physics()
{
    intersectionMap.clear();
    colliders.clear();
}

bool Physics::IntersectCircles(Vector3 centerA, float radiusA, Vector3 centerB, float radiusB, Vector3& normal, float& depth)
{
    normal = Vector3::Zero;
    depth = 0;

    float distance = (centerA - centerB).Length();
    float radii = radiusA + radiusB;

    if (distance > radii)
    {
        return false;
    }

    normal = Vector3::Normalize(centerB - centerA);
    depth = radii - distance;

    return true;
}

void Physics::Update()
{
    if (colliders.size() < 2)
    {
        return;
    }

    Vector3 normal = Vector3::Zero;
    float depth = 0;

    // Loop through all the colliders comparing each collider to all of the others
    for (int i = 0; i < colliders.size() - 1; i++)
    {
        CircleCollider* colliderA = colliders[i];

        for (int j = i + 1; j < colliders.size(); j++)
        {
            CircleCollider* colliderB = colliders[j];

            CollisionPhase phase = CollisionPhase::None;
            bool isTrigger = colliderA->IsTrigger() || colliderB->IsTrigger();

            if (IntersectCircles(colliderA->GetCenter(), colliderA->GetRadius(), colliderB->GetCenter(), colliderB->GetRadius(), normal, depth))
            {
                phase = SetIntersecting(colliderA, colliderB, true);

                if (!isTrigger)
                {
                    Vector3 positionA = colliderA->GetGameObject()->GetTransform()->GetPosition();
                    positionA -= normal * (depth / 2.0f);
                    colliderA->GetGameObject()->GetTransform()->SetPosition(positionA);

                    Vector3 positionB = colliderB->GetGameObject()->GetTransform()->GetPosition();
                    positionB += normal * (depth / 2.0f);
                    colliderB->GetGameObject()->GetTransform()->SetPosition(positionB);
                }
            }
            else
            {
                phase = SetIntersecting(colliderA, colliderB, false);
            }

            if (collisionCallback && phase != CollisionPhase::None)
            {
                collisionCallback(colliderA, colliderB, phase, isTrigger, normal, depth);
            }
        }
    }
}

void Physics::AddCollider(CircleCollider* collider)
{
    colliders.emplace_back(collider);
}

void Physics::RemoveCollider(CircleCollider* collider)
{
    auto iterator = std::find(colliders.begin(), colliders.end(), collider);
    colliders.erase(iterator);
}

bool Physics::IsIntersecting(CircleCollider* colliderA, CircleCollider* colliderB)
{
    auto iterator = intersectionMap.find({ colliderA, colliderB });

    return (iterator != intersectionMap.end()) ? iterator->second : false;
}

CollisionPhase Physics::SetIntersecting(CircleCollider* colliderA, CircleCollider* colliderB, bool intersecting)
{
    bool currentInsection = IsIntersecting(colliderA, colliderB);

    if (currentInsection == intersecting)
    {
        return currentInsection ? CollisionPhase::Stay : CollisionPhase::None;
    }

    CollisionPhase phase = currentInsection ? CollisionPhase::Exit : CollisionPhase::Enter;
    intersectionMap[{ colliderA, colliderB }] = intersecting;
    return phase;
}