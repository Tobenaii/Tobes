#pragma once
#include "Tobes/Common/Math/Vector3.h"

struct Matrix
{
	float m11;
	float m12;
	float m13;
	float m14;
	float m21;
	float m22;
	float m23;
	float m24;
	float m31;
	float m32;
	float m33;
	float m34;
	float m41;
	float m42;
	float m43;
	float m44;

	Matrix()
	{
		m11 = 1;
		m12 = 0;
		m13 = 0;
		m14 = 0;

		m21 = 0;
		m22 = 1;
		m23 = 0;
		m24 = 0;

		m31 = 0;
		m32 = 0;
		m33 = 1;
		m34 = 0;

		m41 = 0;
		m42 = 0;
		m43 = 0;
		m44 = 1;
	}

	Matrix(const float* ptr)
	{
		for (int i = 0; i < 15; i++)
		{
			*(&(m11) + i) = *(ptr + i);
		}
	}

	Matrix operator*(const Matrix& rhs) const
	{
		Matrix result;
		result.m11 = (((m11 * rhs.m11) + (m12 * rhs.m21)) + (m13 * rhs.m31)) + (m14 * rhs.m41);
		result.m12 = (((m11 * rhs.m12) + (m12 * rhs.m22)) + (m13 * rhs.m32)) + (m14 * rhs.m42);
		result.m13 = (((m11 * rhs.m13) + (m12 * rhs.m23)) + (m13 * rhs.m33)) + (m14 * rhs.m43);
		result.m14 = (((m11 * rhs.m14) + (m12 * rhs.m24)) + (m13 * rhs.m34)) + (m14 * rhs.m44);

		result.m21 = (((m21 * rhs.m11) + (m22 * rhs.m21)) + (m23 * rhs.m31)) + (m24 * rhs.m41);
		result.m22 = (((m21 * rhs.m12) + (m22 * rhs.m22)) + (m23 * rhs.m32)) + (m24 * rhs.m42);
		result.m23 = (((m21 * rhs.m13) + (m22 * rhs.m23)) + (m23 * rhs.m33)) + (m24 * rhs.m43);
		result.m24 = (((m21 * rhs.m14) + (m22 * rhs.m24)) + (m23 * rhs.m34)) + (m24 * rhs.m44);

		result.m31 = (((m31 * rhs.m11) + (m32 * rhs.m21)) + (m33 * rhs.m31)) + (m34 * rhs.m41);
		result.m32 = (((m31 * rhs.m12) + (m32 * rhs.m22)) + (m33 * rhs.m32)) + (m34 * rhs.m42);
		result.m33 = (((m31 * rhs.m13) + (m32 * rhs.m23)) + (m33 * rhs.m33)) + (m34 * rhs.m43);
		result.m34 = (((m31 * rhs.m14) + (m32 * rhs.m24)) + (m33 * rhs.m34)) + (m34 * rhs.m44);

		result.m41 = (((m41 * rhs.m11) + (m42 * rhs.m21)) + (m43 * rhs.m31)) + (m44 * rhs.m41);
		result.m42 = (((m41 * rhs.m12) + (m42 * rhs.m22)) + (m43 * rhs.m32)) + (m44 * rhs.m42);
		result.m43 = (((m41 * rhs.m13) + (m42 * rhs.m23)) + (m43 * rhs.m33)) + (m44 * rhs.m43);
		result.m44 = (((m41 * rhs.m14) + (m42 * rhs.m24)) + (m43 * rhs.m34)) + (m44 * rhs.m44);
		return result;
	}
};

inline Matrix Translate(const Vector3& position)
{
	Matrix result;
	result.m11 = 1;
	result.m12 = 0;
	result.m13 = 0;
	result.m14 = 0;
	result.m21 = 0;
	result.m22 = 1;
	result.m23 = 0;
	result.m24 = 0;
	result.m31 = 0;
	result.m32 = 0;
	result.m33 = 1;
	result.m34 = 0;
	result.m41 = position.x;
	result.m42 = position.y;
	result.m43 = position.z;
	result.m44 = 1;
	return result;
}

inline Matrix Perspective(float fieldOfView, float aspectRatio, float nearPlaneDistance, float farPlaneDistance)
{
	Matrix result;
	float num = 1.f / ((float)tan((double)(fieldOfView * 0.5f)));
	float num9 = num / aspectRatio;
	result.m11 = num9;
	result.m12 = result.m13 = result.m14 = 0;
	result.m22 = num;
	result.m21 = result.m23 = result.m24 = 0;
	result.m31 = result.m32 = 0.f;
	result.m33 = farPlaneDistance / (nearPlaneDistance - farPlaneDistance);
	result.m34 = -1;
	result.m41 = result.m42 = result.m44 = 0;
	result.m43 = (nearPlaneDistance * farPlaneDistance) / (nearPlaneDistance - farPlaneDistance);
	return result;
}

inline Matrix LookAt(const Vector3& cameraPosition, const Vector3& cameraTarget, const Vector3& cameraUpVector)
{
	Matrix result;
	Vector3 vector = Normalize(cameraPosition - cameraTarget);
	Vector3 vector2 = Normalize(Cross(cameraUpVector, vector));
	Vector3 vector3 = Cross(vector, vector2);
	result.m11 = vector2.x;
	result.m12 = vector3.x;
	result.m13 = vector.x;
	result.m14 = 0.f;
	result.m21 = vector2.y;
	result.m22 = vector3.y;
	result.m23 = vector.y;
	result.m24 = 0.f;
	result.m31 = vector2.z;
	result.m32 = vector3.z;
	result.m33 = vector.z;
	result.m34 = 0.f;
	result.m41 = -Dot(vector2, cameraPosition);
	result.m42 = -Dot(vector3, cameraPosition);
	result.m43 = -Dot(vector, cameraPosition);
	result.m44 = 1.f;
	return result;
}