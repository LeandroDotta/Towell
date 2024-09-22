#include "Matrix3.h"

using namespace Towell;

static float matrix3Identity[3][3] =
{
	{ 1.0f, 0.0f, 0.0f },
	{ 0.0f, 1.0f, 0.0f },
	{ 0.0f, 0.0f, 1.0f },
};
const Matrix3 Matrix3::Identity(matrix3Identity);