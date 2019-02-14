#pragma once
#include "p2Math.h"
#include "p2Fixture.h"
#include <vector>
#include "p2QuadTree.h"

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
	}

	p2BodyType type;
	p2Vec2 position;
	float angle;
	p2Vec2 linearVelocity;
	float gravityScale;
};

class p2Body
{
private:
	friend class p2World;
	friend class p2Fixture;

	p2Body(const p2BodyDef* bodyDef, p2World* world, p2QuadTree* tree);
	~p2Body();

	void Update(float dt, p2Vec2 gravity);
	void CalculateMassData();

private:
	p2World* m_world;

	p2BodyType m_type;
	p2Vec2 m_position;
	float m_rotation;

	p2Vec2 m_linearVelocity;
	float m_angularVelocity;

	float m_gravityScale;
	float m_mass;

	float m_I;

	p2Vec2 m_centre;

	std::vector<p2Fixture*> m_fixtures;

	p2QuadTree* m_tree;

public:
	inline p2Vec2 GetPosition() const { return m_position; }
	inline p2Vec2 GetVelocity() const { return m_linearVelocity; }
	inline float GetRotation() const { return m_rotation; }
	inline float GetMass() const { return m_mass; }
	inline p2BodyType GetType() const { return m_type; }
	inline void SetVelocity(p2Vec2 vel) { if (m_type == p2_kinematicBody)return; m_linearVelocity = vel; }
	inline void SetPosition(p2Vec2 newPos) { m_position = newPos; }
	void CreateFixture(const p2FixtureDef* shape);
	void ApplyForce(const p2Vec2& force, const p2Vec2& point);
};