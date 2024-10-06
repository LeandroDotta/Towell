#ifndef TOWELL_RENDERER_H
#define TOWELL_RENDERER_H

#include <unordered_map>
#include <SDL.h>
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "VertexArray.h"
#include "window/Window.h"
#include "scene/SpriteRenderer.h"
#include "scene/ShapeRenderer.h"

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

		void AddShape(ShapeRenderer* shape);
		void RemoveShape(ShapeRenderer* shape);

		Window* GetWindow() const { return window; }

	private:
		Window* window;
		SDL_GLContext context;

		Shader* spriteShader;
		Shader* shapeShader;
		Mesh* meshTriangle;
		Mesh* meshQuad;

		std::vector<class SpriteRenderer*> sprites;
		std::vector<class ShapeRenderer*> shapes;

		bool LoadShaders();
	};
}

#endif // TOWELL_RENDERER_H