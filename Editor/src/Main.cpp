#include "Editor.h"

using namespace Towell;

int main(int argc, char* argv[])
{
	Log::Init(Log::LevelTrace);
	TW_INFO("Initializing Towell Engine...");

	Editor* editor = new Editor();
	editor->Run();
	delete editor;
	return 0;
}