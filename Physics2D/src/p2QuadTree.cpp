#include "p2QuadTree.h"
#include "p2Node.h"

p2QuadTree::p2QuadTree()
{
	p2NodeBounds bounds;
	bounds.centre = p2Vec2(400, 400);
	bounds.height = 800;
	bounds.width = 800;
	m_baseNode = new p2Node(bounds, Centre, this);
	m_baseNode->m_isLeaf = true;
}

void p2QuadTree::AddFixture(p2Fixture * fixture)
{
	m_baseNode->AddFixture(fixture);
}

void p2QuadTree::Update()
{
	for (p2Node* node : m_leafNodes)
		node->Update();
}

void p2QuadTree::AddLeafNode(p2Node * node)
{
	m_leafNodes.push_back(node);
}
