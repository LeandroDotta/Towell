#include "ShapeRenderer.h"
#include "Transform.h"

using namespace Towell;

ShapeRenderer::ShapeRenderer(Shape type, int drawOrder, int updateOrder) : ShapeRenderer(type, 0, 0, drawOrder, updateOrder)
{
}

ShapeRenderer::ShapeRenderer(Shape type, float width, float height, int drawOrder, int updateOrder) : Renderer2DComponent(updateOrder),
	type(type), width(width), height(height), drawOrder(drawOrder)
{
	this->color = Color::White;
}

ShapeRenderer::ShapeRenderer(Shape type, float width, float height, Color color, int drawOrder, int updateOrder) : Renderer2DComponent(updateOrder),
	type(type), width(width), height(height), color(color), drawOrder(drawOrder)
{
}

ShapeRenderer::~ShapeRenderer()
{
}

void ShapeRenderer::Draw(Shader* shader, Mesh* mesh)
{
	Renderer2DComponent::Draw(shader, mesh);

	shader->SetColorUniform("uColor", color);
	mesh->Draw();
}
