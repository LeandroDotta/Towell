#ifndef TOWELL_SAMPLE_SCENE_H
#define TOWELL_SAMPLE_SCENE_H

#include <scene/Scene.h>
#include <math/Vector3.h>

using namespace Towell;

class SampleScene : public Scene
{
public:
	SampleScene();

private:
	void CreateSpaceshipAtPosition(Vector3 position);
};

#endif // TOWELL_SAMPLE_SCENE_H

