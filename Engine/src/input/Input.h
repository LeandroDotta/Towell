#ifndef TOWELL_INPUT_H
#define TOWELL_INPUT_H

#include "SDLInputManager.h"

namespace Towell::Input
{
	void Init();
	void Shutdown();

	bool IsKeyPressed(Input::KeyCode key);

	InputManager* GetInstance();
}

#endif // TOWELL_INPUT_H
