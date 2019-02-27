#include "p2Body.h"
#include "p2World.h"
#include <iostream>

p2Body::p2Body(const p2BodyDef* bodyDef, p2World* world)
{
	m_world = world;
	m_type = bodyDef->type;
	m_position = bodyDef->position;
	m_rotation = bodyDef->angle;
	m_linearVelocity = bodyDef->linearVelocity;
	m_gravityScale = bodyDef->gravityScale;
}

p2Body::~p2Body()
{
}



void p2Body::Update(float dt, p2Vec2 gravity)
{
	m_collision = nullptr;
	m_isColliding = false;
	m_position += m_linearVelocity * dt;
	m_rotation += m_angularVelocity * dt;

	//TODO: Clean this up

	if (m_linearVelocity.x > 0)
		m_linearVelocity.x -= 35 * dt;
	if (m_linearVelocity.y > 0)
		m_linearVelocity.y -= 35 * dt;

	if (m_linearVelocity.x < 0)
		m_linearVelocity.x += 35 * dt;
	if (m_linearVelocity.y < 0)
		m_linearVelocity.y += 35 * dt;

	if (m_angularVelocity > 0)
		m_angularVelocity -= 15 * dt;
	if (m_angularVelocity < 0)
		m_angularVelocity += 15 * dt;

	ApplyForce(gravity * m_mass * dt, m_centre);
}

void p2Body::ApplyForce(const p2Vec2& force, const p2Vec2& point)
{
	if (m_type == p2_kinematicBody)
		return;
	m_linearVelocity += force / m_mass;
	
	float angularForce = p2Cross(m_centre - point, force * 0.005f);
	m_angularVelocity += angularForce / m_I;
}

p2BodyDef p2Body::GetState()
{
	p2BodyDef def;
	def.angle = m_rotation;
	def.angularVelocity = m_angularVelocity;
	def.gravityScale = m_gravityScale;
	def.linearVelocity = m_linearVelocity;
	def.position = m_position;
	return def;
}

void p2Body::SetState(p2BodyDef def)
{
	m_rotation = def.angle;
	m_angularVelocity = def.angularVelocity;
	m_gravityScale = def.gravityScale;
	m_linearVelocity = def.linearVelocity;
	m_position = def.position;
}

void p2Body::CreateFixture(const p2FixtureDef* shape)
{
	p2Fixture* fixture = new p2Fixture(this, shape);
	m_fixtures.push_back(fixture);

	m_world->m_fixtures.push_back(fixture);
	CalculateMassData();
}

void p2Body::CalculateMassData()
{
	p2MassData* massData = m_fixtures[0]->GetMassData();
	//TODO: Do This for every fixture
	m_I = massData->I;
	m_mass = massData->mass;
	m_centre = m_position + massData->centre;
}


