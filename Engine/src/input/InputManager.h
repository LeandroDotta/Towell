#ifndef TOWELL_INPUT_MANAGER_H
#define TOWELL_INPUT_MANAGER_H

#include "KeyCode.h"

namespace Towell
{
	class InputManager
	{
	public:
		InputManager() {}
		virtual ~InputManager() {}

		virtual void Update() = 0;
		virtual bool IsKeyPressed(Input::KeyCode key) = 0;
	};
}

#endif // TOWELL_INPUT_MANAGER_H
