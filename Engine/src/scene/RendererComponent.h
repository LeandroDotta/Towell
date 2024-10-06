#ifndef TOWELL_RENDERER_COMPONENT_H
#define TOWELL_RENDERER_COMPONENT_H

#include "Component.h"
#include "rendering/Shader.h"
#include "rendering/Mesh.h"

namespace Towell
{
	class RendererComponent : public Component
	{
	public:
		RendererComponent(int updateOrder = 0) : Component(updateOrder) {}

		virtual void Draw(Shader* shader, Mesh* mesh) = 0;
	};
}

#endif // !TOWELL_RENDERER_COMPONENT_H



