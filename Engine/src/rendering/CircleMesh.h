#ifndef TOWELL_CIRCLE_MESH_H
#define TOWELL_CIRCLE_MESH_H

#include "Mesh.h"

namespace Towell
{
	class CircleMesh : public Mesh
	{
	public:
		CircleMesh(const unsigned int segments = 32);

		void Draw() override;

	private:
		unsigned int numIndices;
	};
}


#endif // TOWELL_CIRCLE_MESH_H




