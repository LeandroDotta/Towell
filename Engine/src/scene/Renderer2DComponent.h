#ifndef TOWELL_RENDERER_2D_COMPONENT_H
#define TOWELL_RENDERER_2D_COMPONENT_H

#include "RendererComponent.h"

namespace Towell
{
	class Renderer2DComponent : public RendererComponent
	{
	public:
		Renderer2DComponent(int drawOrder = 0, int updateOrder = 0);

		void Draw(Shader* shader, Mesh* mesh) override;

		int GetDrawOrder() const { return drawOrder; }
		virtual float GetWidth() const = 0;
		virtual float GetHeight() const = 0;

	protected:
		int drawOrder;
	};
}

#endif // !TOWELL_RENDERER_2D_COMPONENT_H



