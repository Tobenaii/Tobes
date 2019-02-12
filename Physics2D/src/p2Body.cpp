#include "p2Body.h"
#include "p2World.h"

p2Body::p2Body(const p2BodyDef* bodyDef, p2World* world)
{
	m_world = world;
	m_type = bodyDef->type;
	m_position = bodyDef->position;
	m_angle = bodyDef->angle;
	m_linearVelocity = bodyDef->linearVelocity;
	m_gravityScale = bodyDef->gravityScale;
	m_mass = bodyDef->mass;
}

p2Body::~p2Body()
{
}

void p2Body::Update(float dt, p2Vec2 gravity)
{
	m_position += m_linearVelocity * dt;
	ApplyForce(gravity * m_mass * dt);
}

void p2Body::ApplyForce(p2Vec2 force)
{
	if (m_type == p2_kinematicBody)
		return;
	m_linearVelocity += force / m_mass;
}

void p2Body::CreateFixture(const p2FixtureDef* shape)
{
	p2Fixture* fixture = new p2Fixture(this, shape);
	m_fixtures.push_back(fixture);
	m_world->m_fixtures.push_back(fixture);
}


