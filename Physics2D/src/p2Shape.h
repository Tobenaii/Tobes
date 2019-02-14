#pragma once
#include "p2Math.h"

struct p2MassData
{
	//Mass of shape
	float mass;
	//Centre of mass
	p2Vec2 centre;
	//Moment of inertia
	float I;
};

class p2Shape
{
public:
	enum Type
	{
		s_circle = 0,
		s_edge,
		s_polygon
	};

	Type m_type;
	virtual p2Shape* Clone() const = 0;
	int GetShapeID() { return m_shapeID; }
	virtual void ComputeMass(p2MassData* massData, float density) = 0;

protected:
	int m_shapeID;

};
