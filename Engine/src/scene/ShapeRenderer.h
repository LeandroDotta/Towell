#ifndef TOWELL_SHAPE_RENDERER_H
#define TOWELL_SHAPE_RENDERER_H

#include "Renderer2DComponent.h"
#include <rendering/Shader.h>
#include <rendering/Mesh.h>

namespace Towell
{
	class ShapeRenderer : public Renderer2DComponent
	{
	public:
		enum Shape
		{
			Circle,
			Quad,
			Triangle
		};

		ShapeRenderer(Shape type, int drawOrder = 0, int updateOrder = 0);
		ShapeRenderer(Shape type, float width, float height, int drawOrder = 0, int updateOrder = 0);
		ShapeRenderer(Shape type, float width, float height, const Color color, int drawOrder = 0, int updateOrder = 0);
		~ShapeRenderer();

		void Draw(Shader* shader, Mesh* mesh) override;

		float GetWidth() const override { return width; }
		void SetWidth(float width) { this->width = width; }
		float GetHeight() const override { return height; }
		void SetHeight(float height) { this->height = height; }
		int GetDrawOrder() const { return drawOrder; }
		void SetDrawOrder(int drawOrder) { this->drawOrder = drawOrder; }
		Color GetColor() const { return color; }
		void SetColor(Color color) { this->color = color; }
		Shape GetType() const { return type; }
		void SetType(Shape type) { this->type = type; }


	private:
		float width;
		float height;
		int drawOrder;
		Color color;
		Shape type;
	};
}
#endif // TOWELL_SHAPE_RENDERER_H


