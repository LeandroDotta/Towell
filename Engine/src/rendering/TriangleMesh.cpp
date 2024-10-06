#include "TriangleMesh.h"
#include <gl/glew.h>

using namespace Towell;

TriangleMesh::TriangleMesh() : Mesh()
{
	float vertices[] = {
		 0.0f,  0.5f, 0.0f, // top
		 0.5f, -0.5f, 0.0f, // bottom left
		-0.5f, -0.5f, 0.0f  // bottom right
	};
		
	unsigned int indices[] = { 0, 1, 2 };
		
	vertexArray = new VertexArray(vertices, 3, 3, indices, 3);
}

void TriangleMesh::Draw()
{
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
}
