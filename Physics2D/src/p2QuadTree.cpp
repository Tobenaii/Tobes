#include "p2QuadTree.h"
#include "p2Node.h"
#include <algorithm>

p2QuadTree::p2QuadTree(p2World * world)
{
	m_world = world;
	p2NodeBounds bounds;
	bounds.centre = p2Vec2(400, 400);
	bounds.height = 800;
	bounds.width = 800;
	m_baseNode = new p2Node(bounds, Centre, this);
}


void p2QuadTree::AddFixture(p2Fixture * fixture)
{
	m_baseNode->AddFixture(fixture);
}

void p2QuadTree::Update()
{
	for (int i = 0; i < m_leafNodes.size(); i++)
		m_leafNodes[i]->Update();
}

void p2QuadTree::AddLeafNode(p2Node * node)
{
	m_leafNodes.push_back(node);
}

void p2QuadTree::RemoveLeafNode(p2Node * node)
{
	m_leafNodes.erase(std::remove(m_leafNodes.begin(), m_leafNodes.end(), node), m_leafNodes.end());
}


std::vector<p2Node*> p2QuadTree::GetNodes()
{
	return m_leafNodes;
}
