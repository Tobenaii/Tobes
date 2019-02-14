#pragma once
#include <vector>

class p2World;
class p2Fixture;
class p2Node;
class p2QuadTree
{
public:
	p2QuadTree(p2World* world);
	void AddFixture(p2Fixture* fixture);
	void Update();
	void AddLeafNode(p2Node* node);
	void RemoveLeafNode(p2Node* node);
	std::vector<p2Node*> GetNodes();

private:
	friend class p2Node;
	std::vector<p2Node*> m_leafNodes;
	p2Node* m_baseNode;
	p2World* m_world;
};
