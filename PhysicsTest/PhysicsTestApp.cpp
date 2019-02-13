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
	def.position = p2Vec2(210, 800);
	def.mass = 0.1;
	body = m_p2World->CreateBody(&def);
	p2CircleShape circleShape;
	circleShape.m_radius = 10;

	p2FixtureDef fDef;
	fDef.shape = &circleShape;
	body->CreateFixture(&fDef);	

	polyShape.AddVertex(p2Vec2(-1, -1) * 10);
	polyShape.AddVertex(p2Vec2(0, -2) * 10);
	polyShape.AddVertex(p2Vec2(1, -1) * 10);
	polyShape.AddVertex(p2Vec2(2, 0) * 10);
	polyShape.AddVertex(p2Vec2(1, 1) * 10);
	polyShape.AddVertex(p2Vec2(0, 2) * 10);
	polyShape.AddVertex(p2Vec2(-1, 0) * 10);

	//polyShape.AddVertex(p2Vec2(-1, -1) * 100 + p2Vec2(100,0));
	//polyShape.AddVertex(p2Vec2(0, -2) * 100 + p2Vec2(100, 0));
	//polyShape.AddVertex(p2Vec2(1, -1) * 100 + p2Vec2(100, 0));
	//polyShape.AddVertex(p2Vec2(2, 0) * 100 + p2Vec2(100, 0));
	//polyShape.AddVertex(p2Vec2(1, 1) * 100 + p2Vec2(100, 0));
	//polyShape.AddVertex(p2Vec2(0, 2) * 100 + p2Vec2(100, 0));
	//polyShape.AddVertex(p2Vec2(-1, 0) * 100 + p2Vec2(100, 0));

	fDef.shape = &polyShape;
	def.mass = 0.1;
	def.position = p2Vec2(200, 700);
	body2 = m_p2World->CreateBody(&def);
	body2->CreateFixture(&fDef);

	def.mass = 10000;
	p2EdgeShape edge;
	edge.Setp1(p2Vec2(0, 800));
	edge.Setp2(p2Vec2(800, 200));
	fDef.shape = &edge;
	def.type = p2_kinematicBody;
	def.position = p2Vec2(0, 200);
	body3 = m_p2World->CreateBody(&def);
	body3->CreateFixture(&fDef);

	return true;
}

void PhysicsTestApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void PhysicsTestApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	//Update the physics world
	m_p2World->Update(deltaTime);
	pos = body->GetPosition();
	pos2 = body2->GetPosition();
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
	m_2dRenderer->drawCircle(pos.x, pos.y, 10, 0);
	m_2dRenderer->drawLine(0, 800, 800, 200);
	//m_2dRenderer->drawCircle(pos2.x, pos2.y, 10, 0);
	for (int i = 0; i < polyShape.GetVertexCount() - 1; i++)
	{
		p2Vec2 vec1 = body2->GetPosition() + polyShape.GetVertex(i);
		p2Vec2 vec2 = body2->GetPosition() + polyShape.GetVertex(i + 1);
		m_2dRenderer->drawLine(vec1.x, vec1.y, vec2.x, vec2.y);
	}
	p2Vec2 vec1 = body2->GetPosition() + polyShape.GetVertex(polyShape.GetVertexCount() - 1);
	p2Vec2 vec2 = body2->GetPosition() + polyShape.GetVertex(0);
	m_2dRenderer->drawLine(vec1.x, vec1.y, vec2.x, vec2.y);
	
	// done drawing sprites
	m_2dRenderer->end();
}