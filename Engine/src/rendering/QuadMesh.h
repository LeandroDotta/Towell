#ifndef TOWELL_QUAD_MESH_H
#define TOWELL_QUAD_MESH_H

#include "Mesh.h"

namespace Towell
{
	class QuadMesh : public Mesh
	{
	public:
		QuadMesh();

		void Draw() override;
	};
}

#endif // !TOWELL_QUAD_MESH_H



