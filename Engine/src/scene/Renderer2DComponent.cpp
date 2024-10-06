#include "Renderer2DComponent.h"
#include "Transform.h"

using namespace Towell;

Renderer2DComponent::Renderer2DComponent(int drawOrder, int updateOrder) : RendererComponent(updateOrder), drawOrder(drawOrder)
{
}

void Renderer2DComponent::Draw(Shader* shader, Mesh* mesh)
{
	Matrix4 scaleMatrix = Matrix4::CreateScale(
		GetWidth(),
		GetHeight(),
		1.0f
	);

	Matrix4 world = scaleMatrix * gameObject->GetTransform()->GetWorldTransform();

	shader->SetMatrixUniform("uWorldTransform", world);
}
