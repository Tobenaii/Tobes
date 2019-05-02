#pragma once
#include "p2Shape.h"

class p2CircleShape : public p2Shape
{
public:
	p2CircleShape();
	p2Shape* Clone() const { return new p2CircleShape(*this); }
	p2MassData* ComputeMass(float density);

	Vector2 m_pos;
	float m_radius;
};
