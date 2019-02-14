#pragma once
#include <vector>

class p2Fixture;
class p2Node;
class p2QuadTree
{
public:
	p2QuadTree();
	void AddFixture(p2Fixture* fixture);
	void Update();
	void AddLeafNode(p2Node* node);

private:
	std::vector<p2Node*> m_leafNodes;
	p2Node* m_baseNode;
};
