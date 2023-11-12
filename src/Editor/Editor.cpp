#include "../Towell.h"

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
	Editor* editor = new Editor();
	editor->Run();
	delete editor;
}