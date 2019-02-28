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
	void FixedUpdate(std::vector<p2Vec2> holes);
	void DrawCircle(p2CircleShape* circle, aie::Renderer2D* renderer);
	void DrawEdge(p2EdgeShape* edge, aie::Renderer2D* renderer);
	void AssignTexture(aie::Texture* texture);
	bool IsColliding() { return m_body->IsColliding(); }
	p2Body* GetBody() { return m_body; }
	void SetCue();
	
private:
	p2Body* m_body;
	p2Vec4 m_colour;
	aie::Texture* m_texture;
	bool m_hasTexture;
	float m_alpha;
	bool m_inHole;
	p2World* m_world;
	bool m_isCue;
};
