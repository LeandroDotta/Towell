#include "SDLInputManager.h"

using namespace Towell;

SDLInputManager::SDLInputManager()
{
}

SDLInputManager::~SDLInputManager()
{
}

void SDLInputManager::Update()
{
	currentKeyStates = SDL_GetKeyboardState(NULL);
}

bool SDLInputManager::IsKeyPressed(Input::KeyCode key)
{
	// The SDL Scancode definition follows the same standard 
	// for the keyboard key values as the KeyCode instance, 
	// so it just has to be casted.
	SDL_Scancode sdlKey = static_cast<SDL_Scancode>(key);
	return currentKeyStates[sdlKey];
}