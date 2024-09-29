#include "SpriteRenderer.h"
#include "Transform.h"
#include <Log.h>

using namespace Towell;

SpriteRenderer::SpriteRenderer(int drawOrder) : 
	drawOrder(drawOrder),
	texture(nullptr)
{
}

SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::Draw(Shader* shader)
{
	if (!texture)
	{
		return;
	}

	Matrix4 scaleMatrix = Matrix4::CreateScale(
		static_cast<float>(texture->GetWidth()),
		static_cast<float>(texture->GetHeight()),
		1.0f
	);

	Matrix4 world = scaleMatrix * gameObject->GetTransform()->GetWorldTransform();

	shader->SetMatrixUniform("uWorldTransform", world);

	texture->SetActive();
	
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}

Vector2 SpriteRenderer::GetSize()
{
	if (!texture)
	{
		return Vector2::Zero;
	}

	return Vector2(
		static_cast<float>(texture->GetWidth()), 
		static_cast<float>(texture->GetWidth())
	);
}
