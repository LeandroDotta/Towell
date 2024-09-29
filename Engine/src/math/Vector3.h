#ifndef TOWELL_VECTOR3_H
#define TOWELL_VECTOR3_H

#include "Math.h"

namespace Towell
{
	class Vector3
	{
	public:
		float x;
		float y;
		float z;

		Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
		explicit Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

		void Set(float x, float y, float z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		Vector3 operator + (const Vector3& other) const
		{
			return Vector3(x + other.x, y + other.y, z + other.z);
		}

		Vector3 operator - (const Vector3& other) const
		{
			return Vector3(x - other.x, y - other.y, z - other.z);
		}

		Vector3 operator * (const Vector3& other) const
		{
			return Vector3(x * other.x, y * other.y, z * other.z);
		}

		Vector3 operator * (float scalar) const
		{
			return Vector3(x * scalar, y * scalar, z * scalar);
		}

		friend Vector3 operator * (float scalar, const Vector3& vec)
		{
			return Vector3(vec.x * scalar, vec.y * scalar, vec.z * scalar);
		}

		Vector3& operator+=(const Vector3& right)
		{
			x += right.x;
			y += right.y;
			z += right.z;
			return *this;
		}

		Vector3& operator-=(const Vector3& right)
		{
			x -= right.x;
			y -= right.y;
			z -= right.z;
			return *this;
		}

		Vector3& operator*=(const Vector3& right)
		{
			x *= right.x;
			y *= right.y;
			z *= right.z;
			return *this;
		}

		Vector3& operator+=(float scalar)
		{
			x += scalar;
			y += scalar;
			z += scalar;
			return *this;
		}

		void Clamp(Vector3& min, Vector3& max)
		{
			this->x = Math::Clamp(this->x, min.x, max.x);
			this->y = Math::Clamp(this->y, min.y, max.y);
			this->z = Math::Clamp(this->z, min.z, max.z);
		}
		
		float Length() const
		{
			return Math::Sqrt(SquaredLength());
		}

		float SquaredLength() const
		{
			return x * x + y * y + z * z;
		}

		void Normalize()
		{
			float length = Length();
			x /= length;
			y /= length;
			z /= length;
		}

		static Vector3 Clamp(Vector3& value, Vector3& min, Vector3& max)
		{
			return Vector3(
				Math::Clamp(value.x, min.x, max.x),
				Math::Clamp(value.y, min.y, max.y),
				Math::Clamp(value.z, min.z, max.z)
			);
		}

		static Vector3 Normalize(const Vector3& vec)
		{
			float length = vec.Length();
			return Vector3(vec.x / length, vec.y / length, vec.z / length);
		}

		static float Dot(const Vector3& a, const Vector3& b)
		{
			return a.x * b.x + a.y * b.y + a.z * b.z;
		}

		static Vector3 Cross(const Vector3& a, const Vector3& b)
		{
			return Vector3(
				a.y * b.z - a.z * b.y,
				a.z * b.x - a.x * b.z,
				a.x * b.y - a.y * b.x
			);
		}

		static Vector3 Reflect(const Vector3& vec, const Vector3& normal)
		{
			return vec - 2.0f * Vector3::Dot(vec, normal) * normal;
		}

		static const Vector3 Zero;
		static const Vector3 One;
		static const Vector3 Up;
		static const Vector3 Right;
		static const Vector3 Down;
		static const Vector3 Left;
		static const Vector3 Forward;
		static const Vector3 Infinity;
		static const Vector3 NegativeInfinity;
	};
}

#endif // TOWELL_VECTOR3_H