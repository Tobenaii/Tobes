#include "p2Node.h"
#include "p2Collision.h"
#include "p2QuadTree.h"
#include "p2Fixture.h"

p2Node::p2Node(const p2NodeBounds & bounds, NodeDir dir, p2QuadTree* tree)
{
	m_quadTree = tree;
	m_bounds.width = bounds.width / 4;
	m_bounds.height = bounds.height / 4;
	switch (dir)
	{
	case TopLeft:
		m_bounds.centre = p2Vec2(bounds.centre.x - bounds.width / 2, bounds.centre.y + bounds.height / 2);
		break;
	case TopRight:
		m_bounds.centre = p2Vec2(bounds.centre.x + bounds.width / 2, bounds.centre.y + bounds.height / 2);
		break;
	case BotLeft:
		m_bounds.centre = p2Vec2(bounds.centre.x - bounds.width / 2, bounds.centre.y - bounds.height / 2);
		break;
	case BotRight:
		m_bounds.centre = p2Vec2(bounds.centre.x + bounds.width / 2, bounds.centre.y - bounds.height / 2);
		break;
	case Centre:
		m_bounds.centre = bounds.centre;
	}
}

void p2Node::AddFixture(p2Fixture* fixture)
{
	if (!m_isLeaf)
	{
		AddToChildNode(fixture);
		for (p2Fixture* fixture : m_fixtures)
		{
			AddToChildNode(fixture);
		}
		m_fixtures.clear();
		return;
	}

	m_fixtures.push_back(fixture);
	if (m_fixtures.size() > MAX_FIXTURES)
	{
		m_isLeaf = false;
		m_topLeft = new p2Node(m_bounds, TopLeft, m_quadTree);
		m_topRight = new p2Node(m_bounds, TopRight, m_quadTree);
		m_botLeft = new p2Node(m_bounds, BotLeft, m_quadTree);
		m_botRight = new p2Node(m_bounds, BotRight, m_quadTree);
		for (p2Fixture* f : m_fixtures)
			AddToChildNode(f);
	}
	else
	{
		if (!m_isLeaf)
		{
			m_quadTree->AddLeafNode(this);
			m_isLeaf = true;
		}
	}
}

void p2Node::Update()
{
	for (int i = 0; i < m_fixtures.size(); i++)
	{
		if (m_fixtures[i] == nullptr)
			return;
		p2Vec2 pos = m_fixtures[i]->GetBodyPos();
		if (pos.x > m_bounds.centre.x + m_bounds.width / 2 || pos.x < m_bounds.centre.x - m_bounds.width / 2 || pos.y > m_bounds.centre.y + m_bounds.height / 2 || pos.y < m_bounds.centre.y - m_bounds.height / 2)
		{
			p2Fixture* fixture = m_fixtures[i];
			m_fixtures[i] = nullptr;
			m_quadTree->AddFixture(fixture);
		}
	}
	CheckCollisions(m_fixtures);
}

void p2Node::AddToChildNode(p2Fixture * fixture)
{
	p2Vec2 pos = fixture->GetBodyPos();
	if (pos.x < m_bounds.centre.x && pos.y > m_bounds.centre.y)
	{
		m_topLeft->AddFixture(fixture);
		return;
	}
	if (pos.x > m_bounds.centre.x && pos.y > m_bounds.centre.y)
	{
		m_topRight->AddFixture(fixture);
		return;
	}
	if (pos.x < m_bounds.centre.x && pos.y < m_bounds.centre.y)
	{
		m_botLeft->AddFixture(fixture);
		return;
	}
	if (pos.x > m_bounds.centre.x && pos.y < m_bounds.centre.y)
	{
		m_botRight->AddFixture(fixture);
		return;
	}
}


