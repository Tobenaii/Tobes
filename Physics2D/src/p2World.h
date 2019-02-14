#pragma once
#include "p2Math.h"
#include <vector>

class p2QuadTree;
class p2Body;
struct p2BodyDef;
class p2Fixture;

class p2World
{
	friend class p2Body;

public:
	p2World(const p2Vec2& gravity, const float fixedTimeStep);
	~p2World();

	p2Body* CreateBody(const p2BodyDef* bodyDef);
	
	void Update(const float dt);

	p2Vec2 GetGravity() const { return m_gravity; }
	void SetGravity(const p2Vec2& gravity) { m_gravity = gravity; }
	std::vector<p2Fixture*> m_staticFixtures;
	void DestroyBody(p2Body* body);

private:
	p2Vec2 m_gravity;
	float m_fixedTimeStep;
	std::vector<p2Body*> m_bodies;
	std::vector<p2Fixture*> m_fixtures;
	p2QuadTree* m_tree;
};
