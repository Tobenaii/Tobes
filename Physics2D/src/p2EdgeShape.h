#pragma once
#include "p2Shape.h"
#include "p2Math.h"

class p2EdgeShape : public p2Shape
{
public:
	p2EdgeShape() { m_shapeID = 3; }
	void Setp1(const p2Vec2 p) { p1 = p; }
	void Setp2(const p2Vec2 p) { p2 = p; }
	p2Vec2 Getp1() const { return p1; }
	p2Vec2 Getp2() const { return p2; }
	p2Shape* Clone() const { return new p2EdgeShape(*this); }
	void ComputeMass(p2MassData* massData, float density);
private:
	p2Vec2 p1, p2;
};