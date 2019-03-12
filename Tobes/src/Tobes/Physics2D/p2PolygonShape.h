#pragma once
#include "p2Shape.h"
#include <math.h>
#include <vector>

class p2PolygonShape : public p2Shape
{
public:
	p2PolygonShape() { m_shapeID = 1; m_vertexCount = 0; m_type = s_polygon;}
	void AddVertex(const p2Vec2 pos);
	void SetAsBox(const float width, const float height);
	p2Vec2 GetVertex(int index) const;
	void SetVertex(int index, p2Vec2 p) { m_vertices[index] = p; }
	int GetVertexCount() const;
	virtual p2Shape* Clone() const;
	p2MassData* ComputeMass(float density);

private:
	friend class p2Fixture;

	std::vector<p2Vec2> m_vertices;
	std::vector<p2Vec2> m_init;
	int m_vertexCount;
};