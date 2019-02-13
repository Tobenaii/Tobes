#pragma once
#include "p2Math.h"
#include "p2Fixture.h"
#include <vector>

class p2World;

//static: zero mass, zero velocity, may be manually moved
//kinematic: zero mass, non-zero velocity set by user, moved by solver
//dynamic: positive mass, non-zero velocity determined by forces, moved by solver
enum p2BodyType
{
	p2_staticBody = 0,
	p2_kinematicBody,
	p2_dynamicBody
};

struct p2BodyDef
{
	p2BodyDef()
	{
		type = p2_staticBody;
		position.Set(0, 0);
		angle = 0;
		linearVelocity.Set(0, 0);
		gravityScale = 1.0f;
		mass = 1.0f;
	}

	p2BodyType type;
	p2Vec2 position;
	float angle;
	p2Vec2 linearVelocity;
	float gravityScale;
	float mass;
};

class p2Body
{
private:
	friend class p2World;
	friend class p2Fixture;

	p2Body(const p2BodyDef* bodyDef, p2World* world);
	~p2Body();

	void Update(float dt, p2Vec2 gravity);

private:
	p2World* m_world;
	p2BodyType m_type;
	p2Vec2 m_position;
	float m_angle;
	p2Vec2 m_linearVelocity;
	float m_gravityScale;
	float m_mass;
	std::vector<p2Fixture*> m_fixtures;

public:
	inline p2Vec2 GetPosition() { return m_position; }
	inline p2Vec2 GetVelocity() { return m_linearVelocity; }
	inline float GetMass() { return m_mass; }
	inline void SetVelocity(p2Vec2 vel) { if (m_type == p2_kinematicBody)return; m_linearVelocity = vel; }
	void CreateFixture(const p2FixtureDef* shape);
	void ApplyForce(p2Vec2 force);
};