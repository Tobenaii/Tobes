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

PhysicsTestApp::PhysicsTestApp() {

}

PhysicsTestApp::~PhysicsTestApp() {

}

bool PhysicsTestApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	m_p2World = new p2World(p2Vec2(0, -10), 0.01f);
	p2BodyDef def;
	def.position = p2Vec2(200, 800);

	body = m_p2World->CreateBody(&def);

	p2CircleShape circleShape;
	circleShape.m_radius = 10;

	p2FixtureDef fDef;
	fDef.shape = &circleShape;
	body->CreateFixture(&fDef);
	
	p2EdgeShape edgeShape;
	edgeShape.Setp1(p2Vec2(0, 700));
	edgeShape.Setp2(p2Vec2(800, 200));

	fDef.shape = &edgeShape;

	def.position = p2Vec2(0, 0);
	def.type = p2_kinematicBody;
	body2 = m_p2World->CreateBody(&def);
	body2->CreateFixture(&fDef);
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
	m_2dRenderer->drawLine(0, 700, 800, 200, 1);
	// done drawing sprites
	m_2dRenderer->end();
}