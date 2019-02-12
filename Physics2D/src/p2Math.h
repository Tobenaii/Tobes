#pragma once
#include <math.h>

struct p2Vec2
{
	p2Vec2() {}

	p2Vec2(float x_, float y_) : x(x_), y(y_) {}
	void Set(float x_, float y_) { x = x_; y = y_; }

	p2Vec2 operator+(const p2Vec2& rhs) const { return p2Vec2(x + rhs.x, y + rhs.y); }
	p2Vec2 operator-(const p2Vec2& rhs) const { return p2Vec2(x - rhs.x, y - rhs.y); }
	p2Vec2 operator+=(const p2Vec2& rhs) { x += rhs.x; y += rhs.y; return *this; }
	p2Vec2 operator-=(const p2Vec2& rhs) { x -= rhs.x; y -= rhs.y; }
	p2Vec2 operator*(const float& rhs) const { return p2Vec2(x * rhs, y * rhs); }
	p2Vec2 operator/(const float& rhs) const { return p2Vec2(x / rhs, y / rhs); }

	float x, y;
};

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
