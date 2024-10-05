#ifndef TOWELL_VERTEX_ARRAY_H
#define TOWELL_VERTEX_ARRAY_H

namespace Towell
{
	class VertexArray
	{
	public:
		VertexArray(const float* verts, unsigned int numVerts, unsigned int vertsSize, const unsigned int* indices, unsigned int numIndices);
		~VertexArray();

		void SetActive();

		unsigned int GetNumIndices() const { return numIndices; }
		unsigned int GetNumVerts() const { return numVerts; }

	private:
		unsigned int numVerts;
		unsigned int numIndices;
		unsigned int vertexBuffer;
		unsigned int indexBuffer;
		unsigned int vertexArray;
	};
}

#endif // TOWELL_VERTEX_ARRAY_H


