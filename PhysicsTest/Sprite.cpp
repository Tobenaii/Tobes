#include "Sprite.h"
#include <p2World.h>

Sprite::Sprite(const p2BodyDef * bDef, const p2FixtureDef * pDef, p2Vec4 colour, p2World * world)
{
	m_body = world->CreateBody(bDef);
	m_body->CreateFixture(pDef);
	m_colour = colour;
	m_hasTexture = false;
	m_alpha = 1;
	m_inHole = false;
	m_world = world;
	m_isCue = false;
}

void Sprite::Draw(aie::Renderer2D * renderer)
{
	renderer->setRenderColour(m_colour.x, m_colour.y, m_colour.z, m_colour.w);
	if (!m_hasTexture)
	{
		for (int i = 0; i < m_body->GetFixtureCount(); i++)
		{
			p2Vec2 pos = m_body->GetPosition();
			p2Shape* shape = m_body->GetFixture(i)->GetShape();
			switch (shape->GetType())
			{
			case p2Shape::s_circle:
				DrawCircle(dynamic_cast<p2CircleShape*>(shape), renderer);
				break;
			case p2Shape::s_edge:
				DrawEdge(dynamic_cast<p2EdgeShape*>(shape), renderer);
				break;
			case p2Shape::s_polygon:
				DrawPolygon(dynamic_cast<p2PolygonShape*>(shape), renderer);
			}
		}
	}
	else
	{
		renderer->setRenderColour(1, 1, 1, m_alpha);
		renderer->drawSprite(m_texture, m_body->GetPosition().x, m_body->GetPosition().y, 0, 0, m_body->GetRotation());
	}
}

void Sprite::DrawCircle(p2CircleShape* circle, aie::Renderer2D* renderer)
{
	p2Vec2 pos = m_body->GetPosition() + circle->GetMassData()->centre;
	renderer->drawCircle(pos.x, pos.y, circle->m_radius);
}

void Sprite::DrawEdge(p2EdgeShape* edge, aie::Renderer2D* renderer)
{
	p2Vec2 p1 = edge->Getp1() + m_body->GetPosition();
	p2Vec2 p2 = edge->Getp2() + m_body->GetPosition();
	renderer->drawLine(p1.x, p1.y, p2.x, p2.y);
}

void Sprite::DrawPolygon(p2PolygonShape * poly, aie::Renderer2D * renderer)
{
	for (int i = 0; i < poly->GetVertexCount(); i++)
	{
		p2EdgeShape edge;
		edge.Setp1(m_body->GetPosition() + poly->GetVertex(i));
		edge.Setp2(m_body->GetPosition() + poly->GetVertex((i == poly->GetVertexCount() - 1) ? 0 : i + 1));
		renderer->drawLine(edge.Getp1().x, edge.Getp1().y, edge.Getp2().x, edge.Getp2().y);
	}
}

void Sprite::AssignTexture(aie::Texture * texture)
{
	m_hasTexture = true;
	m_texture = texture;
}

void Sprite::SetCue()
{
	m_isCue = true;
}

void Sprite::FixedUpdate(std::vector<p2Vec2> holes)
{
	for (p2Vec2 hole : holes)
	{
		if (p2Length(m_body->GetPosition() - hole) <= 15)
		{
			m_inHole = true;
		}
	}
	if (m_inHole)
	{
		if (m_alpha <= 0)
		{
			if (m_isCue)
			{
				m_body->SetPosition(p2Vec2(100 + ((1600 - 200) * 0.29f - 30 * 2), 800 / 2));
				m_alpha = 1;
				m_inHole = false;
			}
			else
				m_world->DestroyBody(m_body);
		}
		else
		{
			m_body->SetVelocity(p2Vec2(0, 0));
			m_alpha -= 0.01f;
			return;
		}
	}
}
