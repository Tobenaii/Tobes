#include "p2World.h"
#include "p2Body.h"
#include <iostream>

p2World::p2World(const p2Vec2 & gravity, const float fixedTimeStep)
{
	m_gravity = gravity;
	m_fixedTimeStep = fixedTimeStep;
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
}

void p2World::Update(const float dt)
{
	static float accumulator = 0;
	accumulator += dt;
	while (accumulator >= m_fixedTimeStep)
	{
		for (p2Body* body : m_bodies)
			body->Update(m_fixedTimeStep, m_gravity);
		accumulator -= m_fixedTimeStep;
	}
	//TODO: Handle extra time in accumulator
}


