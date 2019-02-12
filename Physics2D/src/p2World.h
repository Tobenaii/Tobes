#pragma once
#include "p2Math.h"
#include <vector>

class p2Body;
struct p2BodyDef;

class p2World
{
public:
	p2World(const p2Vec2& gravity, const float fixedTimeStep);
	~p2World();

	p2Body* CreateBody(const p2BodyDef* bodyDef);
	
	void DestroyBody(p2Body* body);
	void Update(const float dt);

	p2Vec2 GetGravity() const { return m_gravity; }
	void SetGravity(const p2Vec2& gravity) { m_gravity = gravity; }

private:
	p2Vec2 m_gravity;
	float m_fixedTimeStep;
	std::vector<p2Body*> m_bodies;
};
