#include "Application.h"
#include <Towell.h>
#include "SampleScene.h"

using namespace Towell;

int main(int argc, char* argv[])
{
	Log::Init(Log::LevelTrace);
	TW_INFO("Starting Towell Engine...");

	Application* app = new Application();
	bool sucess = app->Init();

	if (sucess)
	{
		SampleScene* scene = new SampleScene(app);
		app->AddScene(scene);
		app->Run();
		delete scene;
	}

	delete app;

	return 0;
}