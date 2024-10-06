#ifndef TOWELL_MESH_H
#define TOWELL_MESH_H

#include "VertexArray.h"
#include <string>

namespace Towell
{
	class Mesh
	{
	public:
		Mesh();
		virtual ~Mesh();

		void SetActive();
		virtual void Draw() = 0;

	protected:
		VertexArray* vertexArray;
	};
}

#endif // TOWELL_MESH_H



