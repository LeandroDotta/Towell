#include "Mesh.h"
#include <unordered_map>

using namespace Towell;

Mesh::Mesh() : vertexArray(nullptr) 
{
}

Mesh::~Mesh()
{
	if (vertexArray)
	{
		delete vertexArray;
	}
}

void Mesh::SetActive()
{
	vertexArray->SetActive();
}