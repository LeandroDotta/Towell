#ifndef TOWELL_EDITOR_CIRCLE_COLLIDER_SCENE
#define TOWELL_EDITOR_CIRCLE_COLLIDER_SCENE

#include <scene/Scene.h>

using namespace Towell;

class CircleColliderScene : public Scene
{
public:
	CircleColliderScene();

private:
	void CreatePlayerCircle();
	void CreateCircleAt(char* name, Vector3 position, Color color, bool isTrigger = false);
};

#endif // TOWELL_EDITOR_CIRCLE_COLLIDER_SCENE




