#ifndef TOWELL_RENDERER_H
#define TOWELL_RENDERER_H

#include <SDL.h>
#include "window/Window.h"
#include "Shader.h"
#include "VertexArray.h"
#include "Texture.h"
#include <scene/SpriteRenderer.h>

namespace Towell
{
	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		bool Init();
		void RenderFrame();

		void AddSprite(SpriteRenderer* sprite);
		void RemoveSprite(SpriteRenderer* sprite);

		Window* GetWindow() const { return window; }

	private:
		Window* window;
		SDL_GLContext context;

		Shader* spriteShader;
		VertexArray* spriteVertices;

		std::vector<class SpriteRenderer*> sprites;

		bool LoadShaders();
		void CreateSpriteVerts();
	};
}

#endif // TOWELL_RENDERER_H