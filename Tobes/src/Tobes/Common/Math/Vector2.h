#pragma once
#include <math.h>
#include "Tobes/Core.h"

struct TOBES_API Vector2
{
	float x, y;

	Vector2() : x(0), y(0) {}

	Vector2(float x_, float y_) : x(x_), y(y_) {}
	void Set(float x_, float y_) { x = x_; y = y_; }

	Vector2 operator+(const Vector2& rhs) const { return Vector2(x + rhs.x, y + rhs.y); }
	Vector2 operator-(const Vector2& rhs) const { return Vector2(x - rhs.x, y - rhs.y); }
	Vector2 operator+=(const Vector2& rhs) { x += rhs.x; y += rhs.y; return *this; }
	Vector2 operator-=(const Vector2& rhs) { x -= rhs.x; y -= rhs.y; return *this; }
	Vector2 operator*(const float& rhs) const { return Vector2(x * rhs, y * rhs); }
	Vector2 operator*=(const float& rhs) { x *= rhs; y *= rhs; return *this; }
	Vector2 operator/(const float& rhs) const { return Vector2(x / rhs, y / rhs); }
	Vector2 operator/=(const float& rhs) { x /= rhs; y /= rhs; return *this; }
	bool operator==(const Vector2& rhs) const { return (x == rhs.x && y == rhs.y); }

	static inline float Length(const Vector2& vec2)
	{
		return (float)sqrt(vec2.x * vec2.x + vec2.y * vec2.y);
	}

	static inline float Dot(const Vector2& p1, const Vector2& p2)
	{
		return ((p1.x * p2.x) + (p1.y * p2.y));
	}

	static inline float Cross(const Vector2& p1, const Vector2& p2)
	{
		return (p1.x * p2.y - p1.y * p2.x);
	}

	static inline Vector2 Normalize(const Vector2& v)
	{
		return v / Length(v);
	}
};


struct Rotation
{
	Rotation() {}

	explicit Rotation(float angle) { s = sinf(angle); c = cosf(angle); }

	//Implement GetAngle using Atan2

	Vector2 GetXAxis() const { return Vector2(c, s); }
	Vector2 GetYAxis() const { return Vector2(-s, c); }

	float s, c;
};

struct Transform
{
	Transform() {}

	Transform(const Vector2& position, const Rotation& rotation) : pos(position), rot(rotation) {}

	Vector2 pos;

	struct Rotation rot;
};
