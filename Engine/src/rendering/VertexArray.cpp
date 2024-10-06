#include "VertexArray.h"
#include <GL/glew.h>

using namespace Towell;

VertexArray::VertexArray(const float* verts, unsigned int numVerts, unsigned int vertsSize, const unsigned int* indices, unsigned int numIndices)
	:numVerts(numVerts), numIndices(numIndices)
{
	// Create vertex array
	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	// Create vertex buffer
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, numVerts * vertsSize * sizeof(float), verts, GL_STATIC_DRAW);

	// Create index buffer
	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * vertsSize, 0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * vertsSize, reinterpret_cast<void*>(sizeof(float) * 3));
}

VertexArray::~VertexArray()
{
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteBuffers(1, &indexBuffer);
	glDeleteVertexArrays(1, &vertexArray);
}

void VertexArray::SetActive()
{
	glBindVertexArray(vertexArray);
}
