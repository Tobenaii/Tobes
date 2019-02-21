#pragma once
#include <p2Body.h>
#include <Renderer2D.h>
#include <p2CircleShape.h>
#include <p2EdgeShape.h>

class Sprite
{
public:
	Sprite(const p2BodyDef* bDef, const p2FixtureDef* pDef, p2Vec4 colour, p2World* world);
	void Draw(aie::Renderer2D* renderer);
	void DrawCircle(p2CircleShape* circle, aie::Renderer2D* renderer);
	void DrawEdge(p2EdgeShape* edge, aie::Renderer2D* renderer);
	p2Body* GetBody() { return m_body; }

private:
	p2Body* m_body;
	p2Vec4 m_colour;
};
