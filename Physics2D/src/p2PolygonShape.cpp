#include "p2PolygonShape.h"
#include "p2Math.h"

void p2PolygonShape::AddVertex(const p2Vec2 pos)
{
	m_vertices.push_back(pos);
}

void p2PolygonShape::SetAsBox(const float width, const float height)
{
	m_vertices.push_back(p2Vec2(-width / 2, -height / 2));
	m_vertices.push_back(p2Vec2(width / 2, -height / 2));
	m_vertices.push_back(p2Vec2(width / 2, height / 2));
	m_vertices.push_back(p2Vec2(-width / 2, height / 2));
}
