#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <p2PolygonShape.h>
#include <p2World.h>


class PhysicsTestApp : public aie::Application 
{
public:
	const static int RADIUS = 1;
	PhysicsTestApp();
	virtual ~PhysicsTestApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	void CreateCircle(p2Vec2 pos);

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	p2World* m_p2World;

	std::vector<p2Body*> m_bodies;
	p2Body* polyBody;

	p2PolygonShape poly;
};