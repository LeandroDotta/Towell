#include "Application.h"
#include <Towell.h>

using namespace Towell;

int main(int argc, char* argv[])
{
	Log::Init(Log::LevelTrace);
	TW_INFO("Initializing Towell Engine...");

	Application* app = new Application();
	bool sucess = app->Init();
	
	if (sucess)
	{
		app->Run();
	}
	
	delete app;
	return 0;
}