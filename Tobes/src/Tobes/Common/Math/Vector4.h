#pragma once
#include "Tobes/Core.h"

struct TOBES_API Vector4
{
	float x, y, z, w;

	Vector4() : x(0), y(0), z(0), w(0) {}

	Vector4(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}
	void Set(float x_, float y_, float z_, float w_) { x = x_; y = y_; z = z_; w = w_; }

	Vector4 operator+(const Vector4& rhs) const { return Vector4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w); }
	Vector4 operator-(const Vector4& rhs) const { return Vector4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w); }
	Vector4 operator+=(const Vector4& rhs) { x += rhs.x; y += rhs.y; z += rhs.z; w += rhs.w; return *this; }
	Vector4 operator-=(const Vector4& rhs) { x -= rhs.x; y -= rhs.y; z -= rhs.z; w -= rhs.w; return *this; }
	Vector4 operator*(const float& rhs) const { return Vector4(x * rhs, y * rhs, z * rhs, w * rhs); }
	Vector4 operator*=(const float& rhs) { x *= rhs; y *= rhs; z *= rhs; w *= rhs; return *this; }
	Vector4 operator/(const float& rhs) const { return Vector4(x / rhs, y / rhs, z / rhs, w / rhs); }
	Vector4 operator/=(const float& rhs) { x /= rhs; y /= rhs; z /= rhs; w /= rhs; return *this; }
	bool operator==(const Vector4& rhs) const { return (x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w); }
};
