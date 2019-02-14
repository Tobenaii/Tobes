#pragma once
#include <vector>
#include "p2Math.h"
#include "p2QuadTree.h"

class p2Fixture;
struct p2NodeBounds
{
	p2NodeBounds()
	{
		width = 0;
		height = 0;
		centre = p2Vec2(0, 0);
	}

	float width;
	float height;
	p2Vec2 centre;
};

enum NodeDir{TopLeft, TopRight, BotLeft, BotRight, Centre};

class p2Node
{
	const static int MAX_FIXTURES = 10;

public:
	p2QuadTree* m_quadTree;
	p2Node(const p2NodeBounds& bounds, NodeDir dir, p2QuadTree* tree);
	void AddFixture(p2Fixture* fixture);
	void Update();
	bool m_isLeaf;

private:
	std::vector<p2Fixture*> m_fixtures;
	p2NodeBounds m_bounds;
	p2Node* m_topLeft;
	p2Node* m_topRight;
	p2Node* m_botLeft;
	p2Node* m_botRight;

	void AddToChildNode(p2Fixture* fixture);
};
