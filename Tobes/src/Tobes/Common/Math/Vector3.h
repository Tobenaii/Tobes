#pragma once
#include <math.h>
#include "Tobes/Core.h"

struct TOBES_API Vector3
{
	float x, y, z;

	Vector3() : x(0), y(0), z(0) {}

	Vector3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
	void Set(float x_, float y_, float z_) { x = x_; y = y_; z = z_; }

	Vector3 operator+(const Vector3& rhs) const { return Vector3(x + rhs.x, y + rhs.y, z + rhs.z); }
	Vector3 operator-(const Vector3& rhs) const { return Vector3(x - rhs.x, y - rhs.y, z - rhs.z); }
	Vector3 operator+=(const Vector3& rhs) { x += rhs.x; y += rhs.y; z += rhs.z; return *this; }
	Vector3 operator-=(const Vector3& rhs) { x -= rhs.x; y -= rhs.y; z -= rhs.z; return *this; }
	Vector3 operator*(const float& rhs) const { return Vector3(x * rhs, y * rhs, z * rhs); }
	Vector3 operator*=(const float& rhs) { x *= rhs; y *= rhs; z *= rhs; return *this; }
	Vector3 operator/(const float& rhs) const { return Vector3(x / rhs, y / rhs, z / rhs); }
	Vector3 operator/=(const float& rhs) { x /= rhs; y /= rhs; z /= rhs; return *this; }
	bool operator==(const Vector3& rhs) const { return (x == rhs.x && y == rhs.y && z == rhs.z); }

	static inline float Length(const Vector3& vec3)
	{
		return (float)sqrt(vec3.x * vec3.x + vec3.y * vec3.y + vec3.z * vec3.z);
	}

	static inline float Dot(const Vector3& p1, const Vector3& p2)
	{
		return ((p1.x * p2.x) + (p1.y * p2.y) + (p1.z * p2.z));
	}

	static inline Vector3 Cross(const Vector3& p1, const Vector3& p2)
	{
		return Vector3(p1.y * p2.z - p1.z * p2.y, p1.z * p2.x - p1.x * p2.z, p1.x * p2.y - p1.y * p2.x);
	}

	static inline Vector3 Normalize(const Vector3& v)
	{
		return v / Length(v);
	}
};



