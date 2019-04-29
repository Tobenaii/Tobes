#pragma once
#include <math.h>

struct Vector2
{
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

	float x, y;
};

struct Vector3
{
	Vector3() :x(0), y(0), z(0) {}
	Vector3(float x_, float y_, float z_) : x(x_), y(y_), z(z_){}

	float x, y, z;
};

struct p2Vec4
{
	p2Vec4() : x(0), y(0), z(0), w(0) {}
	p2Vec4(float x_, float y_, float z_, float w_) { x = x_; y = y_; z = z_; w = w_; }
	void Set(float x_, float y_, float z_, float w_) { x = x_; y = y_; z = z_; w = w_; }

	float x, y, z, w;
};

inline float p2Length(const Vector2& vec2)
{
	return (float)sqrt(vec2.x * vec2.x + vec2.y * vec2.y);
}

inline float p2Dot(const Vector2& p1, const Vector2& p2)
{
	return ((p1.x * p2.x) + (p1.y * p2.y));
}

inline float p2Cross(const Vector2& p1, const Vector2& p2)
{
	return (p1.x * p2.y - p1.y * p2.x);
}

inline Vector2 p2Normalize(const Vector2& v)
{
	return v / p2Length(v);
}

struct p2Rot
{
	p2Rot() {}

	explicit p2Rot(float angle) { s = sinf(angle); c = cosf(angle); }

	//Implement GetAngle using Atan2

	Vector2 GetXAxis() const { return Vector2(c, s); }
	Vector2 GetYAxis() const { return Vector2(-s, c); }

	float s, c;
};

struct p2Transform
{
	p2Transform() {}

	p2Transform(const Vector2& position, const p2Rot& rotation) : pos(position), rot(rotation) {}

	Vector2 pos;
	p2Rot rot;
};
