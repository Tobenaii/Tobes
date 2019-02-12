#pragma once
#include "p2Shape.h"

class p2Body;

struct p2FixtureDef
{
	p2FixtureDef()
	{
		shape = nullptr;
		restitution = 0;
	}

	const p2Shape* shape;
	float restitution;
};

class p2Fixture
{
private:
	friend class p2Body;
	friend class p2World;

	p2Fixture(p2Body* body, const p2FixtureDef* def) { m_body = body; m_shape = new p2Shape(*def->shape); m_restitution = def->restitution; }
	p2Body* m_body;
	p2Shape* m_shape;
	float m_restitution;
	//TODO: Friction
};
