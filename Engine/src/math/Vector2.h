#ifndef TOWELL_VECTOR2_H
#define TOWELL_VECTOR2_H

#include "Math.h"

namespace Towell
{
	class Vector2
	{
	public:
		float x;
		float y;

		Vector2() : x(0.0f), y(0.0f) {}
		explicit Vector2(float x, float y) : x(x), y(y) {}

		void Set(float x, float y)
		{
			this->x = x;
			this->y = y;
		}

		Vector2 operator + (const Vector2& other) const
		{
			return Vector2(x + other.x, y + other.y);
		}

		Vector2 operator - (const Vector2& other) const
		{
			return Vector2(x - other.x, y - other.y);
		}

		Vector2 operator * (const Vector2& other) const
		{
			return Vector2(x * other.x, y * other.y);
		}

		Vector2 operator * (float scalar) const
		{
			return Vector2(x * scalar, y * scalar);
		}

		friend Vector2 operator * (float scalar, const Vector2& vec)
		{
			return Vector2(vec.x * scalar, vec.y * scalar);
		}

		Vector2& operator+=(const Vector2& right)
		{
			x += right.x;
			y += right.y;
			return *this;
		}

		Vector2& operator-=(const Vector2& right)
		{
			x -= right.x;
			y -= right.y;
			return *this;
		}

		Vector2& operator*=(const Vector2& right)
		{
			x *= right.x;
			y *= right.y;
			return *this;
		}

		Vector2& operator+=(float scalar)
		{
			x += scalar;
			y += scalar;
			return *this;
		}

		void Clamp(Vector2& min, Vector2& max)
		{
			this->x = Math::Clamp(this->x, min.x, max.x);
			this->y = Math::Clamp(this->y, min.y, max.y);
		}

		float Length() const
		{
			return Math::Sqrt(SquaredLength());
		}

		float SquaredLength() const
		{
			return x * x + y * y;
		}

		void Normalize()
		{
			float length = Length();
			x /= length;
			y /= length;
		}

		static Vector2 Clamp(Vector2& value, Vector2& min, Vector2& max)
		{
			return Vector2(
				Math::Clamp(value.x, min.x, max.x),
				Math::Clamp(value.y, min.y, max.y)
			);
		}

		static Vector2 Normalize(const Vector2& vec)
		{
			float length = vec.Length();
			return Vector2(vec.x / length, vec.y / length);
		}

		static float Dot(const Vector2& a, const Vector2& b)
		{
			return a.x * b.x + a.y * b.y;
		}

		static Vector2 Reflect(const Vector2& vec, const Vector2& normal)
		{
			return vec - 2.0f * Vector2::Dot(vec, normal) * normal;
		}

		static const Vector2 Zero;
		static const Vector2 One;
		static const Vector2 Up;
		static const Vector2 Right;
		static const Vector2 Down;
		static const Vector2 Left;
	};
}

#endif // TOWELL_VECTOR2_H