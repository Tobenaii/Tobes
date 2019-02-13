#include "p2PolygonShape.h"
#include "p2Math.h"

void p2PolygonShape::AddVertex(const p2Vec2 pos)
{
	m_vertices.push_back(pos);
	m_vertexCount++;
}

void p2PolygonShape::SetAsBox(const float width, const float height)
{
	m_vertices.clear();
	m_vertices.push_back(p2Vec2(-width / 2, -height / 2));
	m_vertices.push_back(p2Vec2(width / 2, -height / 2));
	m_vertices.push_back(p2Vec2(width / 2, height / 2));
	m_vertices.push_back(p2Vec2(-width / 2, height / 2));
	m_vertexCount = 4;
}

p2Vec2 p2PolygonShape::GetVertex(int index) const
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
