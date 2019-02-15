#include "PhysicsTestApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <p2Body.h>
#include <Gizmos.h>
#include <glm/vec2.hpp>
#include <glm/vec4.hpp>
#include <p2CircleShape.h>
#include <p2EdgeShape.h>
#include <p2PolygonShape.h>
#include <math.h>
#include <algorithm>
#define _USE_MATH_DEFINES

PhysicsTestApp::PhysicsTestApp() {

}

PhysicsTestApp::~PhysicsTestApp() {

}

bool PhysicsTestApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	m_p2World = new p2World(p2Vec2(0, -50), 0.01f);

	p2BodyDef def;
	def.position = p2Vec2(100, 100);
	p2EdgeShape edge;
	p2FixtureDef fDef;

	const int merp = 50;
	poly.AddVertex(p2Vec2(-1, -1) * merp);
	poly.AddVertex(p2Vec2(1, -1) * merp);
	poly.AddVertex(p2Vec2(1, 1) * merp);
	poly.AddVertex(p2Vec2(0, 1.5) * merp);
	poly.AddVertex(p2Vec2(-1, 1) * merp);

	def.position = p2Vec2(400, 800);
	fDef.shape = &poly;
	fDef.density = 0.001;
	polyBody = m_p2World->CreateBody(&def);
	polyBody->CreateFixture(&fDef);
	fDef.density = 1;
	def.type = p2_kinematicBody;
	edge.Setp1(p2Vec2(0, 800));
	edge.Setp2(p2Vec2(400, 0));
	fDef.shape = &edge;




	m_p2World->CreateBody(&def)->CreateFixture(&fDef);

	edge.Setp1(p2Vec2(800, 800));
	edge.Setp2(p2Vec2(400, 0));
	m_p2World->CreateBody(&def)->CreateFixture(&fDef);


	//poly.AddVertex(p2Vec2(-1, 1) * 10);
	//poly.AddVertex(p2Vec2(-1, -1) * 10);
	//poly.AddVertex(p2Vec2(1, -1) * 10);
	//poly.AddVertex(p2Vec2(1, 1) * 10);

	def.type = p2_dynamicBody;
	def.position = p2Vec2(400, 800);
	fDef.shape = &poly;
	polyBody = m_p2World->CreateBody(&def);
	polyBody->CreateFixture(&fDef);
	return true;
}

void PhysicsTestApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void PhysicsTestApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	if (input->isMouseButtonDown(0))
	{
		CreateCircle(p2Vec2(input->getMouseX(), input->getMouseY()));
	}
	polyPos = polyBody->GetPosition();
	//Update the physics world
	m_p2World->Update(deltaTime);

	m_p2World->Update(0);
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void PhysicsTestApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();
	// draw your stuff here!
	// output some text, uses the last used colour
	m_2dRenderer->setRenderColour(1, 1, 1, 1);

	m_2dRenderer->drawLine(0, 800, 400, 0);
	m_2dRenderer->drawLine(800, 800, 400, 0);

	for (p2Body* body : m_bodies)
	{
		if (body)
		{
			p2Vec2 p2 = p2Vec2(cos(body->GetRotation()), sin(body->GetRotation())) * RADIUS;
			m_2dRenderer->setRenderColour(1, 1, 1, 1);
			m_2dRenderer->drawCircle(body->GetPosition().x, body->GetPosition().y, RADIUS);
			m_2dRenderer->setRenderColour(1, 0, 0, 1);
			m_2dRenderer->drawLine(body->GetPosition().x, body->GetPosition().y, body->GetPosition().x + p2.x, body->GetPosition().y + p2.y);

			if (body->GetPosition().y + RADIUS < 0)
			{
				p2Body* bye = body;
				m_bodies.erase(std::remove(m_bodies.begin(), m_bodies.end(), bye), m_bodies.end());
				m_p2World->DestroyBody(body);
			}
		}
	}

	for (int i = 0; i < poly.GetVertexCount(); i++)
	{
		p2Vec2 p1 = poly.GetVertex(i);
		p2Vec2 p2 = poly.GetVertex((i == poly.GetVertexCount() - 1) ? 0 : i + 1);
		m_2dRenderer->drawLine(polyPos.x + p1.x, polyPos.y + p1.y, polyPos.x + p2.x, polyPos.y + p2.y);
	}

	for (int i = 0; i < poly.GetVertexCount(); i++)
	{
		p2Vec2 vec1 = poly.GetVertex(i);
		p2Vec2 vec2 = poly.GetVertex((i == poly.GetVertexCount() - 1) ? 0 : i + 1);
		p2Vec2 pos = polyBody->GetPosition();
		m_2dRenderer->drawLine(pos.x + vec1.x, pos.y + vec1.y, pos.x + vec2.x, pos.y + vec2.y);
	}

	
	// done drawing sprites
	m_2dRenderer->end();
}

void PhysicsTestApp::CreateCircle(p2Vec2 pos)
{
	p2BodyDef def;
	def.position = pos;
	def.type = p2_dynamicBody;

	p2FixtureDef fDef;
	p2CircleShape shape;
	shape.m_radius = RADIUS;
	fDef.shape = &shape;
	fDef.density = 1;

	p2Body* body = m_p2World->CreateBody(&def);
	body->CreateFixture(&fDef);
	m_bodies.push_back(body);
}
