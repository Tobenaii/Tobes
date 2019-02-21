#include "p2Fixture.h"
#include "p2Body.h"

p2Shape * p2Fixture::GetShape() const
{
	return m_shape;
}

p2Body * p2Fixture::GetBody() const
{
	return m_body;
}

p2Vec2 p2Fixture::GetBodyPos() const
{
	return m_body->GetPosition();
}

p2Vec2 p2Fixture::GetBodyVelocity() const
{
	return m_body->GetVelocity();
}

p2MassData* p2Fixture::GetMassData() const
{
	return m_shape->ComputeMass( m_density);
}

