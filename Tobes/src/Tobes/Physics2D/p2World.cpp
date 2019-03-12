#include "p2World.h"
#include "p2Body.h"
#include "p2Collision.h"
#include <iostream>
#include <algorithm>

p2World::p2World(const p2Vec2 & gravity, const float fixedTimeStep)
{
	m_gravity = gravity;
	m_fixedTimeStep = fixedTimeStep;
	m_firstSim = true;
}

p2World::~p2World()
{
}

p2Body* p2World::CreateBody(const p2BodyDef* bodyDef)
{
	p2Body* body = new p2Body(bodyDef, this);
	m_bodies.push_back(body);
	return body;
}

void p2World::DestroyBody(p2Body * body)
{
	m_fixtures.erase(std::remove(m_fixtures.begin(), m_fixtures.end(), body->m_fixtures[0]), m_fixtures.end());
	m_bodies.erase(std::remove(m_bodies.begin(), m_bodies.end(), body), m_bodies.end());
}

void p2World::SetUpdateCallback(void(*cb)())
{
	m_cb = cb;
}

void p2World::Update(const float dt)
{
	ResetSimulation();
	static float accumulator = 0;
	accumulator += dt;
	while (accumulator >= m_fixedTimeStep)
	{
		for (p2Body* body : m_bodies)
			body->Update(m_fixedTimeStep, m_gravity);
		//TODO: Make sure fixtures on same body don't do any collision response
		CheckCollisions(m_fixtures);
		accumulator -= m_fixedTimeStep;
		m_cb();
	}
	//TODO: Handle extra time in accumulator
}

void p2World::Simulate(const float dt)
{
	for (p2Body* body : m_bodies)
	{
		if (m_firstSim)
		{
			p2BodyDef def = body->GetState();
			m_defs.push_back(def);
		}
		body->Update(dt, m_gravity);
	}
	m_firstSim = false;
	CheckCollisions(m_fixtures);
}

void p2World::ResetSimulation()
{
	m_firstSim = true;
	if (m_defs.size() == 0)
		return;
	for (int i = 0; i < m_bodies.size(); i++)
	{
		m_bodies[i]->SetState(m_defs[i]);
	}
	m_defs.clear();
}



