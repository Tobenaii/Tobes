#include "p2CircleShape.h"
#define _USE_MATH_DEFINES
#include <math.h>


p2CircleShape::p2CircleShape()
{
	m_shapeID = 0;
	m_type = s_circle;
}

p2MassData* p2CircleShape::ComputeMass(float density)
{
	m_massData = new p2MassData();
	m_massData->mass = density * (float)M_PI * m_radius * m_radius;
	m_massData->centre = m_pos;
	m_massData->I = m_massData->mass * (0.5f * m_radius * m_radius + Vector2::Dot(m_pos, m_pos));
	return m_massData;
}
