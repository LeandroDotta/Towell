#include "Application.h"
#include <Towell.h>
#include "SampleScene.h"

using namespace Towell;

int main(int argc, char* argv[])
{
	Log::Init(Log::LevelTrace);
	TW_INFO("Starting Towell Engine...");

	Application* app = Application::Init("./Assets");
	
	if (app)
	{
		SampleScene* scene = new SampleScene(app);
		app->AddScene(scene);
		app->Run();
		delete scene;
	}

	Application::Shutdown();

	return 0;
}