#ifndef TOWELL_MATRIX4_H
#define TOWELL_MATRIX4_H

#include <memory.h>
#include "Vector3.h"

namespace Towell
{
	class Matrix4
	{
	public:
		float mat[4][4];

		Matrix4()
		{
			*this = Matrix4::Identity;
		}

		explicit Matrix4(float elements[4][4])
		{
			memcpy(mat, elements, 16 * sizeof(float));
		}

		Matrix4 operator+(const Matrix4& other) const
		{
			Matrix4 result;

			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					result.mat[i][j] = mat[i][j] + other.mat[i][j];
				}
			}

			return result;
		}

		Matrix4 operator-(const Matrix4& other) const
		{
			Matrix4 result;

			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					result.mat[i][j] = mat[i][j] - other.mat[i][j];
				}
			}

			return result;
		}

		Matrix4 operator*(const Matrix4& other) const
		{
			Matrix4 result;

			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					result.mat[i][j] = 0.0f;

					for (int k = 0; k < 4; ++k)
					{
						result.mat[i][j] += mat[i][k] * other.mat[k][j];
					}
				}
			}

			return result;
		}

		Matrix4 operator*(float scalar) const 
		{
			Matrix4 result;

			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					result.mat[i][j] = mat[i][j] * scalar;
				}
			}

			return result;
		}

		Matrix4& operator*=(const Matrix4& right)
		{
			*this = *this * right;
			return *this;
		}

		Vector3 GetTranslation() const
		{
			return Vector3(mat[3][0], mat[3][1], mat[3][2]);
		}

		/**
		* @brief Get the X axis of the matrix (Forward)
		*/
		Vector3 GetXAxis() const
		{
			return Vector3::Normalize(Vector3(mat[0][0], mat[0][1], mat[0][2]));
		}

		/**
		* @brief Get the Y axis of the matrix (Left)
		*/
		Vector3 GetYAxis() const
		{
			return Vector3::Normalize(Vector3(mat[1][0], mat[1][1], mat[1][2]));
		}

		/**
		* @brief Get the Z axis of the matrix (Up)
		*/
		Vector3 GetZAxis() const
		{
			return Vector3::Normalize(Vector3(mat[2][0], mat[2][1], mat[2][2]));
		}

		/**
		* @brief Extract the scale component from the matrix
		*/
		Vector3 GetScale() const
		{
			Vector3 scaleVector
			{
				Vector3(mat[0][0], mat[0][1], mat[0][2]).Length(),
				Vector3(mat[1][0], mat[1][1], mat[1][2]).Length(),
				Vector3(mat[2][0], mat[2][1], mat[2][2]).Length(),
			};

			return scaleVector;
		}

		static Matrix4 CreateScale(float xScale, float yScale, float zScale)
		{
			float scaleMatrix[4][4] =
			{
				{ xScale, 0.0f,   0.0f,   0.0f },
				{ 0.0f,	  yScale, 0.0f,   0.0f },
				{ 0.0f,	  0.0f,   zScale, 0.0f },
				{ 0.0f,   0.0f,   0.0f,   1.0f },
			};

			return Matrix4(scaleMatrix);
		}

		static Matrix4 CreateScale(const Vector3& scaleVector)
		{
			return CreateScale(scaleVector.x, scaleVector.y, scaleVector.z);
		}

		static Matrix4 CreateScale(float scale)
		{
			return CreateScale(scale, scale, scale);
		}

		/**
		* @brief Create a rotation matrix about the X axis
		*
		* @param theta The theta angle, in radians
		* @return A new Matrix4 rotated in angle
		*/
		static Matrix4 CreateRotationX(float theta)
		{
			float rotationMatrix[4][4] =
			{
				{ 1.0f,  0.0f,			   0.0f,			 0.0f },
				{ 0.0f,  Math::Cos(theta), Math::Sin(theta), 0.0f },
				{ 0.0f, -Math::Sin(theta), Math::Cos(theta), 0.0f },
				{ 0.0f,  0.0f,			   0.0f,			 1.0f },
			};

			return Matrix4(rotationMatrix);
		}

		/**
		* @brief Create a rotation matrix about the Y axis
		*
		* @param theta The theta angle, in radians
		* @return A new Matrix4 rotated in angle
		*/
		static Matrix4 CreateRotationY(float theta)
		{
			float rotationMatrix[4][4] =
			{
				{ Math::Cos(theta), 0.0f, -Math::Sin(theta), 0.0f },
				{ 0.0f,				1.0f,  0.0f,			 0.0f },
				{ Math::Sin(theta), 0.0f,  Math::Cos(theta), 0.0f },
				{ 0.0f,				0.0f,  0.0f,			 1.0f }
			};

			return Matrix4(rotationMatrix);
		}

		/**
		* @brief Create a rotation matrix about the Z axis
		*
		* @param theta The theta angle, in radians
		* @return A new Matrix4 rotated in angle
		*/
		static Matrix4 CreateRotationZ(float theta)
		{
			float rotationMatrix[4][4] =
			{
				{  Math::Cos(theta), Math::Sin(theta), 0.0f, 0.0f },
				{ -Math::Sin(theta), Math::Cos(theta), 0.0f, 0.0f },
				{  0.0f,			 0.0f,			   1.0f, 0.0f },
				{  0.0f,			 0.0f,			   0.0f, 1.0f },
			};

			return Matrix4(rotationMatrix);
		}

		static Matrix4 CreateTranslation(const Vector3& translation)
		{
			float translationMatrix[4][4] =
			{
				{ 1.0f,			 0.0f,			0.0f,		   0.0f },
				{ 0.0f,			 1.0f,			0.0f,		   0.0f },
				{ 0.0f,			 0.0f,			1.0f,		   0.0f },
				{ translation.x, translation.y, translation.z, 1.0f },
			};

			return Matrix4(translationMatrix);
		}

		static Matrix4 CreateViewProjection(float width, float height)
		{
			float projectionMatrix[4][4] =
			{
				{ 2.0f / width, 0.0f,		   0.0f, 0.0f },
				{ 0.0f,			2.0f / height, 0.0f, 0.0f },
				{ 0.0f,			0.0f,		   1.0f, 0.0f },
				{ 0.0f,			0.0f,		   1.0f, 1.0f }
			};
			return Matrix4(projectionMatrix);
		}

		static const Matrix4 Identity;
	};
}

#endif // TOWELL_MATRIX4_H