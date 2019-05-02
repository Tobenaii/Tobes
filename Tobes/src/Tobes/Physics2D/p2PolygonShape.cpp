#include "p2PolygonShape.h"

void p2PolygonShape::AddVertex(const Vector2 pos)
{
	m_vertices.push_back(pos);
	m_init.push_back(pos);
	m_vertexCount++;
}

void p2PolygonShape::SetAsBox(const float width, const float height)
{
	m_vertices.clear();
	m_vertices.push_back(Vector2(-width / 2, -height / 2));
	m_vertices.push_back(Vector2(width / 2, -height / 2));
	m_vertices.push_back(Vector2(width / 2, height / 2));
	m_vertices.push_back(Vector2(-width / 2, height / 2));
	m_vertexCount = 4;
}

Vector2 p2PolygonShape::GetVertex(int index) const
{
	return m_vertices[index];
}

int p2PolygonShape::GetVertexCount() const
{
	return m_vertexCount;
}

p2Shape * p2PolygonShape::Clone() const
{
	return new p2PolygonShape(*this);
}

p2MassData* p2PolygonShape::ComputeMass(float density)
{
	m_massData = new p2MassData();
	m_massData->mass = 0.3f;
	m_massData->centre = Vector2(0, 0);
	float radius = Vector2::Length(GetVertex(0));
	for (int i = 1; i < GetVertexCount(); i++)
	{
		if (Vector2::Length(GetVertex(i)) > radius)
			radius = Vector2::Length(GetVertex(i));
	}
	m_massData->I = m_massData->mass * (0.5f * 30 * 30 + Vector2::Dot(Vector2(0,0), Vector2(0, 0)));
	return m_massData;
}
