#include "TestScreen.h"
#include <window/Screen.h>
#include "MockWindow.h"

using namespace Towell::Test;

void TestScreen::Run()
{
	MockWindow* window = new MockWindow();
	Screen::Init(window);

	test("GetWidth", []() -> void {
		int width = Screen::GetWidth();
		assertEqual(512, width, "Should return the screen width");
	});

	test("GetHeight", []() -> void {
		int height = Screen::GetHeight();
		assertEqual(256, height, "Should return the screen height");
	});

	Screen::Shutdown();
}
