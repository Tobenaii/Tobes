#pragma once
#include <math.h>

struct p2Vec2
{
	p2Vec2() : x(0), y(0) {}

	p2Vec2(float x_, float y_) : x(x_), y(y_) {}
	void Set(float x_, float y_) { x = x_; y = y_; }

	p2Vec2 operator+(const p2Vec2& rhs) const { return p2Vec2(x + rhs.x, y + rhs.y); }
	p2Vec2 operator-(const p2Vec2& rhs) const { return p2Vec2(x - rhs.x, y - rhs.y); }
	p2Vec2 operator+=(const p2Vec2& rhs) { x += rhs.x; y += rhs.y; return *this; }
	p2Vec2 operator-=(const p2Vec2& rhs) { x -= rhs.x; y -= rhs.y; return *this; }
	p2Vec2 operator*(const float& rhs) const { return p2Vec2(x * rhs, y * rhs); }
	p2Vec2 operator*=(const float& rhs) { x *= rhs; y *= rhs; return *this; }
	p2Vec2 operator/(const float& rhs) const { return p2Vec2(x / rhs, y / rhs); }
	p2Vec2 operator/=(const float& rhs) { x /= rhs; y /= rhs; return *this; }
	bool operator==(const p2Vec2& rhs) const { return (x == rhs.x && y == rhs.y); }

	float x, y;
};

struct p2Vec4
{
	p2Vec4() : x(0), y(0), z(0), w(0) {}
	p2Vec4(float x_, float y_, float z_, float w_) { x = x_; y = y_; z = z_; w = w_; }
	void Set(float x_, float y_, float z_, float w_) { x = x_; y = y_; z = z_; w = w_; }

	float x, y, z, w;
};

inline float p2Length(const p2Vec2& vec2)
{
	return (float)sqrt(vec2.x * vec2.x + vec2.y * vec2.y);
}

inline float p2Dot(const p2Vec2& p1, const p2Vec2& p2)
{
	return ((p1.x * p2.x) + (p1.y * p2.y));
}

inline float p2Cross(const p2Vec2& p1, const p2Vec2& p2)
{
	return (p1.x * p2.y - p1.y * p2.x);
}

struct p2Rot
{
	p2Rot() {}

	explicit p2Rot(float angle) { s = sinf(angle); c = cosf(angle); }

	//Implement GetAngle using Atan2

	p2Vec2 GetXAxis() const { return p2Vec2(c, s); }
	p2Vec2 GetYAxis() const { return p2Vec2(-s, c); }

	float s, c;
};

struct p2Transform
{
	p2Transform() {}

	p2Transform(const p2Vec2& position, const p2Rot& rotation) : pos(position), rot(rotation) {}

	p2Vec2 pos;
	p2Rot rot;
};
