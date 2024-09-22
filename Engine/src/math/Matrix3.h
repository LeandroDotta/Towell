#ifndef TOWELL_MATRIX3_H
#define TOWELL_MATRIX3_H

#include <memory.h>
#include "Vector2.h"

namespace Towell
{
	class Matrix3
	{
	public:
		float mat[3][3];

		Matrix3()
		{
			*this = Matrix3::Identity;
		}

		explicit Matrix3(float elements[3][3])
		{
			memcpy(mat, elements, 9 * sizeof(float));
		}

		Matrix3 operator+(const Matrix3& other) const
		{
			Matrix3 result;
			
			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					result.mat[i][j] = mat[i][j] + other.mat[i][j];
				}
			}

			return result;
		}

		Matrix3 operator-(const Matrix3& other) const
		{
			Matrix3 result;

			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					result.mat[i][j] = mat[i][j] - other.mat[i][j];
				}
			}

			return result;
		}

		Matrix3 operator*(const Matrix3& other) const 
		{
			Matrix3 result;

			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					result.mat[i][j] = 0.0f;

					for (int k = 0; k < 3; ++k)
					{
						result.mat[i][j] += mat[i][k] * other.mat[k][j];
					}
				}
			}

			return result;
		}

		Matrix3 operator*(const float scalar) const
		{
			Matrix3 result;

			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					result.mat[i][j] = mat[i][j] * scalar;
				}
			}

			return result;
		}

		Matrix3& operator*=(const Matrix3& right)
		{
			*this = *this * right;
			return *this;
		}

		static Matrix3 CreateScale(float xScale, float yScale)
		{
			float scaleMatrix[3][3] =
			{
				{ xScale, 0.0f,   0.0f },
				{ 0.0f,   yScale, 0.0f },
				{ 0.0f,   0.0f,   0.0f },
			};

			return Matrix3(scaleMatrix);
		}

		static Matrix3 CreateScale(const Vector2& scaleVector)
		{
			return CreateScale(scaleVector.x, scaleVector.y);
		}

		static Matrix3 CreateScale(float scale)
		{
			return CreateScale(scale, scale);
		}

		/**
		* @brief Create a rotation matrix about the Z axis
		* 
		* @param theta The theta angle, in radians
		* @return A new Matrix3 rotated in angle
		*/
		static Matrix3 CreateRotation(float theta)
		{
			float roationMatrix[3][3] =
			{
				{  Math::Cos(theta), Math::Sin(theta), 0.0f },
				{ -Math::Sin(theta), Math::Cos(theta), 0.0f },
				{ 0.0f,			     0.0f,			   1.0f },
			};

			return Matrix3(roationMatrix);
		}

		/**
		* @brief Create a translation matrix out of a Vector (on the xy-plane)
		* 
		* @param translation The translation Vector
		* @return A new translated Matrix3
		*/
		static Matrix3 CreateTranslation(const Vector2& translation)
		{
			float translationMatrix[3][3] =
			{
				{ 1.0f,			 0.0f,			0.0f },
				{ 0.0f,			 1.0f,			0.0f },
				{ translation.x, translation.y, 1.0f },
			};

			return Matrix3(translationMatrix);
		}

		static const Matrix3 Identity;
	};
}

#endif // TOWELL_MATRIX3_H



