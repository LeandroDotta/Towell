#include "ShapeRenderer.h"
#include "Transform.h"

using namespace Towell;

ShapeRenderer::ShapeRenderer(Shape type, int drawOrder, int updateOrder) : ShapeRenderer(type, 0, 0, drawOrder, updateOrder)
{
}

ShapeRenderer::ShapeRenderer(Shape type, int width, int height, int drawOrder, int updateOrder) : Component(updateOrder),
	type(type), width(width), height(height), drawOrder(drawOrder)
{
	this->color = Color::White;
}

ShapeRenderer::ShapeRenderer(Shape type, int width, int height, Color color, int drawOrder, int updateOrder) : Component(updateOrder),
	type(type), width(width), height(height), color(color), drawOrder(drawOrder)
{
}

ShapeRenderer::~ShapeRenderer()
{
}

void ShapeRenderer::Draw(Shader* shader, Mesh* mesh)
{
	Matrix4 scaleMatrix = Matrix4::CreateScale(
		static_cast<float>(GetWidth()),
		static_cast<float>(GetHeight()),
		1.0f
	);

	Matrix4 world =  scaleMatrix * gameObject->GetTransform()->GetWorldTransform();

	shader->SetColorUniform("uColor", color);
	shader->SetMatrixUniform("uWorldTransform", world);

	mesh->Draw();
}
