#ifndef TOWELL_EDITOR_MOVEMENT_COMPONENT
#define TOWELL_EDITOR_MOVEMENT_COMPONENT

#include <scene/Component.h>
#include <math/Vector2.h>

using namespace Towell;

class MovementComponent : public Component
{
public: 
	MovementComponent(int updateOrder = 0);

	void Update(float deltaTime) override;
	
	float GetSpeed() const { return speed; }
	void SetSpeed(float speed);
	Vector2 GetDirection() const { return direction; }
	void SetDirection(Vector2 direction);


protected:
	float speed;
	Vector2 direction;


private:
	Vector2 velocity;
};


#endif // TOWELL_EDITOR_MOVEMENT_COMPONENT
