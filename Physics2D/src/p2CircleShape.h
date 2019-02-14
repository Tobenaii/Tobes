#pragma once
#include "p2Shape.h"
#include "p2Math.h"

class p2CircleShape : public p2Shape
{
public:
	p2CircleShape();
	p2Shape* Clone() const { return new p2CircleShape(*this); }
	void ComputeMass(p2MassData* massData, float density);

	p2Vec2 m_pos;
	float m_radius;
};
