#pragma once
#include "p2Shape.h"

class p2EdgeShape : public p2Shape
{
public:
	p2EdgeShape() { m_shapeID = 3; m_type = s_edge; }
	void Setp1(const Vector2 p) { p1 = p; }
	void Setp2(const Vector2 p) { p2 = p; }
	Vector2 Getp1() const { return p1; }
	Vector2 Getp2() const { return p2; }
	p2Shape* Clone() const { return new p2EdgeShape(*this); }
	p2MassData* ComputeMass(float density);
private:
	Vector2 p1, p2;
};