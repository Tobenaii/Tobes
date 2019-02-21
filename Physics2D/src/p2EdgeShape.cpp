#include "p2EdgeShape.h"

p2MassData* p2EdgeShape::ComputeMass(float density)
{
	m_massData = new p2MassData();
	m_massData->mass = 100;
	return m_massData;
}
