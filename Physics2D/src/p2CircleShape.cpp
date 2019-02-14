#include "p2CircleShape.h"
#define _USE_MATH_DEFINES
#include <math.h>


p2CircleShape::p2CircleShape()
{
	m_shapeID = 0;
}

void p2CircleShape::ComputeMass(p2MassData * massData, float density)
{
	massData->mass = density * M_PI * m_radius * m_radius;
	massData->centre = m_pos;
	massData->I = massData->mass * (0.5f * m_radius * m_radius + p2Dot(m_pos, m_pos));
}
