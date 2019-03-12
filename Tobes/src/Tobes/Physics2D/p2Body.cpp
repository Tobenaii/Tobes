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

	float frictionL = 100 * dt;
	if (p2Length(m_linearVelocity) > 0)
	{
		p2Vec2 fDir = p2Normalize(m_linearVelocity) * frictionL;
		if (p2Length(m_linearVelocity) < p2Length(fDir))
			m_linearVelocity = p2Vec2(0, 0);
		else
			m_linearVelocity -= fDir;
	}

	float frictionA = 50 * dt;
	if (m_angularVelocity < 0)
	{
		if (m_angularVelocity > frictionA)
			m_angularVelocity = 0;
		else
			m_angularVelocity += frictionA;
	}
	if (m_angularVelocity > 0)
	{
		if (m_angularVelocity < frictionA)
			m_angularVelocity = 0;
		else
			m_angularVelocity -= frictionA;
	}


	for (p2Fixture* fixture : m_fixtures)
		fixture->UpdateRotation(m_rotation);

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


