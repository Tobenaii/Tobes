#include "p2Fixture.h"
#include "p2Body.h"

p2Shape * p2Fixture::GetShape() const
{
	return m_shape;
}

p2Vec2 p2Fixture::GetBodyPos() const
{
	return m_body->GetPosition();
}
