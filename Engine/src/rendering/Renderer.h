#ifndef TOWELL_RENDERER_H
#define TOWELL_RENDERER_H

#include <SDL.h>
#include "window/Window.h"
#include "Shader.h"
#include "VertexArray.h"

namespace Towell
{
	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		bool Init();
		void RenderFrame();
	private:
		Window* window;
		SDL_GLContext context;

		Shader* spriteShader;
		VertexArray* spriteVertices;

		bool LoadShaders();
		void CreateSpriteVerts();
	};
}

#endif // TOWELL_RENDERER_H