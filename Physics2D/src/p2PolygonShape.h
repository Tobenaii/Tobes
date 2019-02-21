#pragma once
#include "p2Shape.h"
#include <vector>

class p2Vec2;

class p2PolygonShape : public p2Shape
{
public:
	p2PolygonShape() { m_shapeID = 1; m_vertexCount = 0; m_type = s_polygon; }
	void AddVertex(const p2Vec2 pos);
	void SetAsBox(const float width, const float height);
	p2Vec2 GetVertex(int index) const;
	int GetVertexCount() const;
	virtual p2Shape* Clone() const;
	p2MassData* ComputeMass(float density);

private:
	std::vector<p2Vec2> m_vertices;
	int m_vertexCount;
};