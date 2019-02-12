#pragma once

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

protected:
	int m_shapeID;
};
