#include <Towell.h>

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
	Towell::Log::Init();
	TW_INFO("Initializing Towell Engine");

	Editor* editor = new Editor();
	editor->Run();
	delete editor;
}