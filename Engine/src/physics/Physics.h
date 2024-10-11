#ifndef TOWELL_PHYSICS_H
#define TOWELL_PHYSICS_H

#include <vector>
#include <math/Vector3.h>
#include <scene/CircleCollider.h>
#include <string>
#include <functional>
#include <map>

namespace Towell
{
	/**
	 * @brief Indicates what phase the collision is
	 */
	enum class CollisionPhase 
	{
		/** No collision happened */
		None, 
		/** Indicates the collision just started. This means that it is the first frame in which the colliders intersect. */
		Enter, 
		/** Indicates the collision started and continues happening, meaning the colliders are intersecting. */
		Stay, 
		/** Indicates the collision exited. This means the colliders are not intersecting anymore (there is no collision at the frame). */
		Exit 
	};

	/**
	 * @brief Callback function type for collision events.
	 *
	 * This typedef defines a callback function that will be invoked when a collision occurs
	 * between two Colliders. The parameters provide information about the collision.
	 *
	 * @param colliderA Pointer to the first Collider involved in the collision.
	 * @param colliderB Pointer to the second Collider involved in the collision.
	 * @param phase The phase of the collision (e.g., entering, staying, exiting).
	 * @param isTrigger Indicates if the collision is a trigger event.
	 * @param normal The normal indicating the direction from colliderA to colliderB.
	 * @param depth The depth of contact are. Also representing the normal length.
	 */
	typedef void (*OnCollision)(CircleCollider*, CircleCollider*, CollisionPhase, bool, Vector3, float);

	/**
	 * @brief A class responsible for managing physics-related calculations.
	 *
	 * The Physics class provides functionality for detecting collisions between
	 * Collider objects and managing a collection of colliders. It allows
	 * users to add and remove colliders, update physics calculations, and set
	 * collision callbacks.
	 */
	class Physics
	{
	public:
		/**
		 * @brief Constructs a Physics object.
		 *
		 * Initializes the physics system and prepares for collider management.
		 */
		Physics();
		/**
		* @brief Destroys the Physics object.
		*
		* Cleans up any resources associated with the physics system.
		*/
		~Physics();

		/**
		 * @brief Checks if two circles intersect.
		 *
		 * It determines whether two circles intersect based on their
		 * centers and radii. If they intersect, the function calculates the normal
		 * vector and depth at the point of intersection.
		 *
		 * @param centerA The center of the first circle.
		 * @param radiusA The radius of the first circle.
		 * @param centerB The center of the second circle.
		 * @param radiusB The radius of the second circle.
		 * @param normal Output parameter for the normal vector at the point of intersection.
		 * @param depth Output parameter for the depth of the intersection.
		 * @return true if the circles intersect, false otherwise.
		 */
		static bool IntersectCircles(Vector3 centerA, float radiusA, Vector3 centerB, float radiusB, Vector3& normal, float& depth);

		/**
		 * @brief Updates the physics system.
		 *
		 * This method processes the current state of colliders and checks for
		 * intersections. 
		 * 
		 * It must be called iteration of the application loop.
		 */
		void Update();

		/**
		 * @brief Adds a collider to the physics system.
		 *
		 * This method registers a CircleCollider with the physics system to enable
		 * collision detection.
		 *
		 * @param collider Pointer to the CircleCollider to be added.
		 */
		void AddCollider(CircleCollider* collider);

		/**
		 * @brief Removes a collider from the physics system.
		 *
		 * This method unregisters a CircleCollider from the physics system,
		 * stopping collision detection for that collider.
		 *
		 * @param collider Pointer to the CircleCollider to be removed.
		 */
		void RemoveCollider(CircleCollider* collider);

		/**
		 * @brief Sets the collision callback function.
		 *
		 * This method allows users to specify a callback function to be called
		 * when a collision is detected.
		 *
		 * @param onCollision The callback function to be invoked on collision events.
		 */
		void SetCollisionCallback(OnCollision onCollision)
		{
			this->collisionCallback = onCollision;
		}
	private:
		// List of colliders managed by the physics system.
		std::vector<class CircleCollider*> colliders;
		// Map tracking intersections between colliders.
		// It stores wheather there was a collision between two colliders in the previous Update cycle, and 
		// uses it to determine the phase of the collision (e.g. entering, staying, exiting)
		std::map<std::pair<CircleCollider*, CircleCollider*>, bool> intersectionMap;

		// Callback function for collision events.
		OnCollision collisionCallback;

		/**
		 * @brief Checks if two colliders were intersecting in the previous update cycle.
		 *
		 * @param colliderA Pointer to the first CircleCollider.
		 * @param colliderB Pointer to the second CircleCollider.
		 * @return true if the colliders were intersecting, false otherwise.
		 */
		bool IsIntersecting(CircleCollider* colliderA, CircleCollider* colliderB);
		/**
		 * @brief Sets the intersection status of two colliders.
		 *
		 * It stores the intersection status between two colliders in the current update cycle and evaluates
		 * the current collision phase comparing it with the previous status.
		 *
		 * @param colliderA Pointer to the first CircleCollider.
		 * @param colliderB Pointer to the second CircleCollider.
		 * @param intersecting The intersection status to set.
		 * @return The collision phase of the intersection.
		 */
		CollisionPhase SetIntersecting(CircleCollider* colliderA, CircleCollider* colliderB, bool intersecting);
	};
}


#endif // TOWELL_PHYSICS_H


