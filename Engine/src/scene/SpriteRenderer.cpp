#include "SpriteRenderer.h"
#include "Transform.h"
#include <Log.h>

using namespace Towell;

SpriteRenderer::SpriteRenderer(int drawOrder, int updateOrder) : Renderer2DComponent(drawOrder, updateOrder),
	texture(nullptr)
{
}

SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::Draw(Shader* shader, Mesh* mesh)
{
	if (!texture)
	{
		return;
	}

	Renderer2DComponent::Draw(shader, mesh);

	texture->SetActive();
	
	mesh->Draw();
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

float SpriteRenderer::GetWidth() const
{
	if (!texture)
	{
		return 0.0f;
	}

	return static_cast<float>(texture->GetWidth());
}

float SpriteRenderer::GetHeight() const
{
	if (!texture)
	{
		return 0.0f;
	}

	return static_cast<float>(texture->GetHeight());
}
