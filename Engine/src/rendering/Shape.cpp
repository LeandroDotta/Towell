#include "Shape.h"

using namespace Towell;

VertexArray* Shape::CreateSprite()
{
	float vertices[] = {
		-0.5f,  0.5f, 0.f, 0.f, 0.f, // top left
		 0.5f,  0.5f, 0.f, 1.f, 0.f, // top right
		 0.5f, -0.5f, 0.f, 1.f, 1.f, // bottom right
		-0.5f, -0.5f, 0.f, 0.f, 1.f  // bottom left
	};

	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	return new VertexArray(vertices, 4, 5, indices, 6);
}

VertexArray* Shape::CreateTriangle()
{
	float vertices[] = {
		 0.0f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f
	};

	unsigned int indices[] = { 0, 1, 2 };

	return new VertexArray(vertices, 3, 3, indices, 3);
}
