#include <Towell.h>

using namespace Towell;

class Editor : public Towell::Application
{
public:
	Editor()
	{

	}

	~Editor()
	{

	}
};		


int main() 
{
	Log::Init(Log::LevelTrace);
	TW_INFO("Initializing Towell Engine...");

	Editor* editor = new Editor();
	editor->Run();
	delete editor;
}