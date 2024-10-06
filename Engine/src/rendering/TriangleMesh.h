#ifndef TOWELL_TRIANGLE_MESH_H
#define TOWELL_TRIANGLE_MESH_H

#include "Mesh.h"

namespace Towell
{
	class TriangleMesh : public Mesh
	{
	public:
		TriangleMesh();

		void Draw() override;
		
	};
}

#endif // TOWELL_TRIANGLE_MESH_H


