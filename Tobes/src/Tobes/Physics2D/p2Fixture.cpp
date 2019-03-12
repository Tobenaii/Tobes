#include "p2Fixture.h"
#include "p2Body.h"
#include "p2PolygonShape.h"

void p2Fixture::UpdateRotation(float rotation)
{
	p2PolygonShape* poly = dynamic_cast<p2PolygonShape*>(m_shape);
	if (!poly)
		return;

	for (int i = 0; i < poly->GetVertexCount(); i++)
	{
		p2Vec2 p = poly->m_init[i];
		poly->SetVertex(i, p2Vec2(p.x * cos(rotation) - p.y * sin(rotation), p.x * sin(rotation) + p.y * cos(rotation)));
	}
}

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

