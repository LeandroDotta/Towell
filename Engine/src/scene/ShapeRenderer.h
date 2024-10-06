#ifndef TOWELL_SHAPE_RENDERER_H
#define TOWELL_SHAPE_RENDERER_H

#include "Component.h"
#include <rendering/Shader.h>
#include <rendering/Mesh.h>

namespace Towell
{
	class ShapeRenderer : public Component
	{
	public:
		enum Shape
		{
			Triangle,
			Quad
		};

		ShapeRenderer(Shape type, int drawOrder = 0, int updateOrder = 0);
		ShapeRenderer(Shape type, int width, int height, int drawOrder = 0, int updateOrder = 0);
		ShapeRenderer(Shape type, int width, int height, const Color color, int drawOrder = 0, int updateOrder = 0);
		~ShapeRenderer();

		virtual void Draw(Shader* shader, Mesh* mesh);

		int GetWidth() const { return width; }
		void SetWidth(int width) { this->width = width; }
		int GetHeight() const { return height; }
		void SetHeight() { this->height = height; }
		int GetDrawOrder() const { return drawOrder; }
		void SetDrawOrder(int drawOrder) { this->drawOrder = drawOrder; }
		Color GetColor() const { return color; }
		void SetColor(Color color) { this->color = color; }
		Shape GetType() const { return type; }
		void SetType(Shape type) { this->type = type; }


	private:
		int width;
		int height;
		int drawOrder;
		Color color;
		Shape type;
	};
}
#endif // TOWELL_SHAPE_RENDERER_H


