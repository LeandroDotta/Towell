#include "Input.h"
#include <Log.h>

using namespace Towell;

static InputManager* instance;

void Input::Init()
{
	instance = new SDLInputManager();
}

void Input::Shutdown()
{
	delete instance;
}

bool Input::IsKeyPressed(Input::KeyCode key)
{
	return instance->IsKeyPressed(key);
}

InputManager* Input::GetInstance()
{
	return instance;
}
