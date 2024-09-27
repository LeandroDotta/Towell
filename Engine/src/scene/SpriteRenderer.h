#ifndef TOWELL_SPRITE_RENDERER_H
#define TOWELL_SPRITE_RENDERER_H

#include "Component.h"
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

		int GetDrawOrder() const { return drawOrder; }

	protected:
		Texture* texture;

		int drawOrder;
	};
}

#endif // TOWELL_SPRITE_RENDERER_H