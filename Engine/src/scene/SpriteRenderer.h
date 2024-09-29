#ifndef TOWELL_SPRITE_RENDERER_H
#define TOWELL_SPRITE_RENDERER_H

#include "Component.h"
#include <math/Vector2.h>
#include <rendering/Shader.h>
#include <rendering/Texture.h>

namespace Towell
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer(int drawOrder = 0);
		~SpriteRenderer();

		virtual void Draw(Shader* shader);
		virtual void SetTexture(Texture* texture) { this->texture = texture; }

		/**
		* @brief Gets the Sprite Renderer texture size.
		* 
		* @return A Vector2 representing the renderer texture size where
		* the X value is equivalent to the width and the Y value to the height.
		* If there's no texture assigned to the Sprite Renderer, it returns a zero Vector
		*/
		Vector2 GetSize();
		int GetDrawOrder() const { return drawOrder; }

	protected:
		Texture* texture;

		int drawOrder;
	};
}

#endif // TOWELL_SPRITE_RENDERER_H