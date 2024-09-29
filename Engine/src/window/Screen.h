#include "Window.h"
#ifndef TOWELL_SCREEN_H
#define TOWELL_SCREEN_H

namespace Towell::Screen
{
	bool Init(Window* window);
	void Shutdown();

	int GetWidth();
	int GetHeight();
}

#endif // TOWELL_SCREEN_H