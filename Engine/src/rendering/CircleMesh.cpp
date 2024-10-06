#include "CircleMesh.h"
#include <gl/glew.h>
#include "math/Math.h"

using namespace Towell;

CircleMesh::CircleMesh(const unsigned int segments)
{
	const float radius = 0.5f;
	const unsigned int numVerts = 3 * (segments + 3);
	numIndices = 3 * segments;
	float* vertices = new float[numVerts];
	unsigned int* indices = new unsigned int[numIndices];

	// Center vertex
	vertices[0] = 0.0f;
	vertices[1] = 0.0f;
	vertices[2] = 0.0f;

	float angleStep = 2.0f * Math::Pi / segments;

	// Generate points on the circle
	for (int i = 0; i <= segments; ++i)
	{
		float angle = i * angleStep;
		vertices[3 * (i + 1)] = radius * Math::Cos(angle);		// x
		vertices[3 * (i + 1) + 1] = radius * Math::Sin(angle);	// y
		vertices[3 * (i + 1) + 2] = 0.0f;						// z
	}

	// Generate indices for each triangle
	for (int i = 0; i < segments; ++i)
	{
		indices[3 * i] = 0;			// Center vertex
		indices[3 * i + 1] = i + 1; // Current vertex on the circle
		indices[3 * i + 2] = i + 2; // Next vertex on the circle
	}

	// Last triangle connects the last vertex to the first one
	indices[3 * (segments - 1) + 2] = 1;

	vertexArray = new VertexArray(vertices, numVerts, 3, indices, numIndices);
}

void CircleMesh::Draw()
{
	glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_INT, nullptr);
}
