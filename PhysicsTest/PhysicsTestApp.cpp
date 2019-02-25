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
	m_p2World = new p2World(p2Vec2(0, 0), 0.005f);

	p2BodyDef bDef;
	p2FixtureDef fDef;
	p2CircleShape cShape;
	p2EdgeShape eShape;
	
	cShape.m_radius = BALL_RADIUS;

	bDef.type = p2_kinematicBody;
	bDef.position = p2Vec2(0, 0);
	fDef.shape = &eShape;

	eShape.Setp1(p2Vec2(100 + BALL_RADIUS * 1.6f, 100));
	eShape.Setp2(p2Vec2(sWidth / 2 - BALL_RADIUS * 1.6f, 100));
	m_sprites.push_back(new Sprite(&bDef, &fDef, p2Vec4(1, 1, 1, 1), m_p2World));

	eShape.Setp1(p2Vec2(sWidth / 2 + BALL_RADIUS * 1.6f, 100));
	eShape.Setp2(p2Vec2(sWidth - 100 - BALL_RADIUS * 1.6f, 100));
	m_sprites.push_back(new Sprite(&bDef, &fDef, p2Vec4(1, 1, 1, 1), m_p2World));

	eShape.Setp1(p2Vec2(100, 100 + BALL_RADIUS * 1.6f));
	eShape.Setp2(p2Vec2(100, sHeight - 100 - BALL_RADIUS * 1.6f));
	m_sprites.push_back(new Sprite(&bDef, &fDef, p2Vec4(1, 1, 1, 1), m_p2World));

	//==============================================================================
	eShape.Setp1(p2Vec2(100 + BALL_RADIUS * 1.6f, sHeight - 100));
	eShape.Setp2(p2Vec2(sWidth / 2 - BALL_RADIUS * 1.6f, sHeight - 100));
	m_sprites.push_back(new Sprite(&bDef, &fDef, p2Vec4(1, 1, 1, 1), m_p2World));

	eShape.Setp1(p2Vec2(sWidth / 2 + BALL_RADIUS * 1.6f, sHeight - 100));
	eShape.Setp2(p2Vec2(sWidth - 100 - BALL_RADIUS * 1.6f, sHeight - 100));
	m_sprites.push_back(new Sprite(&bDef, &fDef, p2Vec4(1, 1, 1, 1), m_p2World));

	eShape.Setp1(p2Vec2(sWidth - 100, 100 + BALL_RADIUS * 1.6f));
	eShape.Setp2(p2Vec2(sWidth - 100, sHeight - 100 - BALL_RADIUS * 1.6f));
	m_sprites.push_back(new Sprite(&bDef, &fDef, p2Vec4(1, 1, 1, 1), m_p2World));

	fDef.shape = &cShape;
	fDef.density = 0.0001f;
	bDef.type = p2_dynamicBody;
	int row = 1;
	p2Vec2 startPos = p2Vec2(sWidth - 100 - ((sWidth - 200) * 0.25f - BALL_RADIUS * 2), sHeight / 2);
	for (int r = 0; r < 5; r++)
	{
		for (int c = 0; c < row; c++)
		{
			p2Vec2 pos(startPos.x + ((BALL_RADIUS + 10) * (row - 1)), startPos.y + ((BALL_RADIUS + 10) * c));
			bDef.position = pos;
			m_sprites.push_back(new Sprite(&bDef, &fDef, p2Vec4(1, 1, 1, 1), m_p2World));
		}
		row++;
		startPos.y -= BALL_RADIUS / 2;
	}
	startPos = p2Vec2(100 + ((sWidth - 200) * 0.25f - BALL_RADIUS * 2), sHeight / 2);
	bDef.position = startPos;
	m_sprites.push_back(new Sprite(&bDef, &fDef, p2Vec4(0, 1, 1, 1), m_p2World));
	//m_sprites[m_sprites.size() - 1]->GetBody()->ApplyForce(p2Vec2(500, 0), p2Vec2(0, 0));
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

	for (Sprite* sprite : m_sprites)
	{
		if (p2Length(sprite->GetBody()->GetVelocity()) > 0.5f)
		{
			p2Vec2 merp = sprite->GetBody()->GetPosition();
			if (merp.x < 0 || merp.x > sWidth || merp.y < 0 || merp.y > sHeight)
			{
				m_canShoot = true;
				continue;
			}
			m_canShoot = false;
			break;
		}
		m_canShoot = true;
	}
	m_mPos = p2Vec2(input->getMouseX(), input->getMouseY());

	if (m_canShoot)
	{
		p2Vec2 ballPos = m_sprites[m_sprites.size() - 1]->GetBody()->GetPosition();

		p2Vec2 dir = ballPos - m_mPos;
		dir = dir / p2Length(dir);
		if (input->wasMouseButtonPressed(0))
			m_sprites[m_sprites.size() - 1]->GetBody()->ApplyForce(dir * 1000, p2Vec2(0, 0));
		else
		{
			m_p2World->Simulate(0.005f);
			m_sprites[m_sprites.size() - 1]->GetBody()->ApplyForce(dir * 1000, p2Vec2(0, 0));
			bool col = m_sprites[m_sprites.size() - 1]->IsColliding();
			while (!col)
			{
				m_p2World->Simulate(0.005f);
				col = m_sprites[m_sprites.size() - 1]->IsColliding();
				p2Vec2 pos = m_sprites[m_sprites.size() - 1]->GetBody()->GetPosition();
			}
			m_col = m_sprites[m_sprites.size() - 1]->GetBody()->GetCollision();
			m_hitPoint = m_sprites[m_sprites.size() - 1]->GetBody()->GetPosition();

			m_p2World->Simulate(0.005f);
			m_colPoint = m_col->GetPosition();
		}
	}
	m_p2World->Update(deltaTime);

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

	for (Sprite* sprite : m_sprites)
		sprite->Draw(m_2dRenderer);

	if (m_canShoot)
	{
		m_2dRenderer->setRenderColour(1, 0, 0, 1);
		p2Vec2 ballPos = m_sprites[m_sprites.size() - 1]->GetBody()->GetPosition();
		p2Vec2 dir = m_mPos - ballPos;
		dir = dir / p2Length(dir);
		dir *= BALL_RADIUS * 2;
		m_2dRenderer->drawLine(ballPos.x, ballPos.y, ballPos.x + dir.x, ballPos.y + dir.y);
		m_2dRenderer->drawLine(ballPos.x, ballPos.y, m_hitPoint.x, m_hitPoint.y);
		p2Vec2 dir2 = m_colPoint - m_col->GetPosition();
		dir2 = dir2 / p2Length(dir2);
		m_2dRenderer->drawLine(m_col->GetPosition().x, m_col->GetPosition().y, m_col->GetPosition().x + dir2.x * 100, m_col->GetPosition().y + dir2.y * 100);
	}

	// done drawing sprites
	m_2dRenderer->end();
}
