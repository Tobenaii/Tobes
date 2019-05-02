#pragma once
#include <vector>
#include "Tobes/Common/Math/Vector2.h"

class p2Body;
struct p2BodyDef;
class p2Fixture;

class p2World
{
	friend class p2Body;

public:
	p2World(const Vector2& gravity, const float fixedTimeStep);
	~p2World();

	p2Body* CreateBody(const p2BodyDef* bodyDef);
	
	void Update(const float dt);
	void Simulate(const float dt);

	Vector2 GetGravity() const { return m_gravity; }
	void SetGravity(const Vector2& gravity) { m_gravity = gravity; }
	void DestroyBody(p2Body* body);
	void SetUpdateCallback(void(*cb)());

private:
	void ResetSimulation();

private:
	void(*m_cb)();
	Vector2 m_gravity;
	float m_fixedTimeStep;
	std::vector<p2Body*> m_bodies;
	std::vector<p2Fixture*> m_fixtures;
	std::vector<p2BodyDef> m_defs;
	bool m_firstSim;
};
