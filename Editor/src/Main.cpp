#include "Application.h"
#include <Towell.h>
#include "./samples/physics-circle-collider-sample/CircleColliderScene.h"

using namespace Towell;

int main(int argc, char* argv[])
{
	Log::Init(Log::LevelTrace);
	TW_INFO("Starting Towell Engine...");

	Application* app = Application::Init("./Assets");
	Application::SetBackgroundColor(Color::Parse("04151f"));
	
	if (app)
	{
		Scene* scene = new CircleColliderScene();
		app->AddScene(scene);
		app->Run();
		delete scene;
	}

	Application::Shutdown();

	return 0;
}