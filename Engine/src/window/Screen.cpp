#include "Screen.h"

using namespace Towell;

static Window* window;

bool Screen::Init(Window* windowReference)
{
    window = windowReference;
    return true;
}

void Screen::Shutdown()
{
    window = nullptr;
}

int Screen::GetWidth()
{
    return window->GetWidth();
}

int Screen::GetHeight()
{
    return window->GetHeight();
}
