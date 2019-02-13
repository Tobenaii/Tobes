#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <p2PolygonShape.h>
#include <p2World.h>


class PhysicsTestApp : public aie::Application 
{
public:

	PhysicsTestApp();
	virtual ~PhysicsTestApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	p2World* m_p2World;
	p2Body* body;
	p2Body* body2;
	p2Body* body3;
	p2Vec2 pos;
	p2Vec2 pos2;
	p2PolygonShape polyShape;
	p2Vec2 merp1;
	p2Vec2 merp2;
};