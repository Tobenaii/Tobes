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
};
