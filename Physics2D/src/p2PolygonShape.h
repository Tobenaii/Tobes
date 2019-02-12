#pragma once
#include "p2Shape.h"
#include <vector>

class p2Vec2;

class p2PolygonShape : p2Shape
{
public:
	void AddVertex(const p2Vec2 pos);
	void SetAsBox(const float width, const float height);

private:
	std::vector<p2Vec2> m_vertices;
};