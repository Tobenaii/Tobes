#pragma once
#include "Tobes/Common/Math/Vector2.h"

struct p2MassData
{
	//Mass of shape
	float mass;
	//Centre of mass
	Vector2 centre;
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
	virtual p2MassData* ComputeMass(float density) = 0;
	inline p2MassData* GetMassData() { return m_massData; }
	inline Type GetType() { return m_type; }

protected:
	int m_shapeID;
	p2MassData* m_massData;
};
