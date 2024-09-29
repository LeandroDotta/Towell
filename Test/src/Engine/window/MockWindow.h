#ifndef TOWELL_MOCK_WINDOW_H
#define TOWELL_MOCK_WINDOW_H

#include <window/Window.h>

using namespace Towell;

typedef void *SDL_GLContext;

namespace Towell::Test
{
	class MockWindow : public Window
	{
	public:
		MockWindow();

		void Update() override {}

		SDL_GLContext CreateOpenGLContext() override { return nullptr; }

		int GetWidth() override { return width; }
		int GetHeight() override { return height; }
		void SetSize(int width, int height) override
		{
			this->width = width;
			this->height = height;
		}
		std::string GetTitle() override { return title; }
		void SetTitle(std::string title) { this->title = title; }


	private:
		int width;
		int height;
		std::string title;
	};
}

#endif // TOWELL_MOCK_WINDOW_H
