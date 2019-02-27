#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <p2PolygonShape.h>
#include <p2World.h>
#include "Sprite.h"

static int sWidth = 1600;
static int sHeight = 800;

class PhysicsTestApp : public aie::Application 
{
public:
	const float BALL_RADIUS = 30;
	const float HOLE_RADIUS = BALL_RADIUS * 1.8f;
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

	std::vector<Sprite*> m_sprites;
	bool m_canShoot;
	p2Vec2 m_mPos;

	p2Vec2 m_hitPoint;
	p2Body* m_col;
	p2Vec2 m_colPoint;

	aie::Texture* m_ball2;
};