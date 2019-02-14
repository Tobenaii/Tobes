#include "p2Body.h"
#include "p2World.h"
#include <iostream>

p2Body::p2Body(const p2BodyDef* bodyDef, p2World* world, p2QuadTree* tree)
{
	m_world = world;
	m_type = bodyDef->type;
	m_position = bodyDef->position;
	m_rotation = bodyDef->angle;
	m_linearVelocity = bodyDef->linearVelocity;
	m_gravityScale = bodyDef->gravityScale;
	m_tree = tree;
}

p2Body::~p2Body()
{
}

void p2Body::Update(float dt, p2Vec2 gravity)
{
	m_position += m_linearVelocity * dt;
	m_rotation += m_angularVelocity * dt;
	ApplyForce(gravity * m_mass * dt, m_centre);
}

void p2Body::ApplyForce(const p2Vec2& force, const p2Vec2& point)
{
	if (m_type == p2_kinematicBody)
		return;
	m_linearVelocity += force / m_mass;
	
	float angularForce = p2Cross(m_centre - point, force);
	m_angularVelocity += angularForce / m_I;
}

void p2Body::CreateFixture(const p2FixtureDef* shape)
{
	p2Fixture* fixture = new p2Fixture(this, shape);
	m_fixtures.push_back(fixture);
	if (m_type != p2_dynamicBody)
	{
		m_world->m_staticFixtures.push_back(fixture);
	}
	else
	{
		//m_world->m_fixtures.push_back(fixture);
		m_tree->AddFixture(fixture);
	}
	CalculateMassData();
}

void p2Body::CalculateMassData()
{
	p2MassData massData;
	//TODO: Do This for every fixture
	m_fixtures[0]->GetMassData(&massData);
	m_I = massData.I;
	m_mass = massData.mass;
	m_centre = m_position + massData.centre;
}


