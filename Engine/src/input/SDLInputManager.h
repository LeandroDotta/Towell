#ifndef TOWELL_SDL_INPUT_H
#define TOWELL_SDL_INPUT_H

#include <SDL.h>
#include "InputManager.h"

namespace Towell
{
	class SDLInputManager : public InputManager
	{
	public:
		SDLInputManager();
		~SDLInputManager() override;

		void Update() override;
		bool IsKeyPressed(Input::KeyCode key) override;


	private:
		const Uint8* currentKeyStates;
	};
}

#endif // TOWELL_SDL_INPUT_H