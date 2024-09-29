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

	inline float Cos(float angle)
	{
		return cosf(angle);
	}

	inline float Sin(float angle)
	{
		return sinf(angle);
	}

	inline float Tan(float angle)
	{
		return tanf(angle);
	}

	inline float Acos(float value)
	{
		return acosf(value);
	}

	inline float Atan2(float y, float x)
	{
		return atan2f(y, x);
	}

	inline int Clamp(int value, int min, int max)
	{
		if (value < min)
			return min;

		if (value > max)
			return max;

		return value;
	}

	inline float Clamp(float value, float min, float max)
	{
		if (value < min)
			return min;

		if (value > max)
			return max;

		return value;
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
