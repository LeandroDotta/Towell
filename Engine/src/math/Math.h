#ifndef TOWELL_MATH_H
#define TOWELL_MATH_H

#include <cmath>
#include <limits>

namespace Towell::Math
{
	const float Pi = 3.1415926535f;
	const float TwoPi = Pi * 2.0f;
	const float Infinity = std::numeric_limits<float>::infinity();
	const float NegativeInfinity = -std::numeric_limits<float>::infinity();

	inline float Abs(float value)
	{
		return fabs(value);
	}

	inline float Floor(float value)
	{
		return floorf(value);
	}

	inline float Round(float value)
	{
		return roundf(value);
	}

	inline float Sqrt(float value)
	{
		return std::sqrtf(value);
	}

	inline bool AreEqual(float x, float y, float epsilon = 0.001f)
	{
		if (Abs(x - y) <= epsilon)
		{
			return true;
		}

		return false;
	}

	inline bool NearZero(float val, float epsilon = 0.001f)
	{
		if (Abs(val) <= epsilon)
		{
			return true;
		}

		return false;
	}
}

#endif // TOWELL_MATH_H
