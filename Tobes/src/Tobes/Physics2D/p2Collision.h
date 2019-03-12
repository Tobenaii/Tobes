#pragma once
#include "p2CircleShape.h"
#include "p2PolygonShape.h"
#include "p2EdgeShape.h"
#include "p2Fixture.h"
#include <vector>

class p2Fixture;

//Circle = 0
//Polygon = 1
//Edge = 3

struct CollisionData
{
	CollisionData()
	{
		collision = false;
		point = p2Vec2(0, 0);
		overlap = 0;
	}

	bool collision;
	p2Vec2 relativeVelocity;
	p2Body* bodyA;
	p2Body* bodyB;
	p2Vec2 normal;
	p2Vec2 point;
	float overlap;
};

typedef void(*fn)(CollisionData*, const p2Shape*, const p2Vec2&, const p2Shape*, const p2Vec2&);

extern fn collisionsFunctionArray[5];

void ResolveCollision(const CollisionData& data);

void CheckCollisions(const std::vector<p2Fixture*> fixtures);

void p2CollideCircles(CollisionData* data, const p2Shape* circleA, const p2Vec2& bodyPosA, const p2Shape* circleB, const p2Vec2& bodyPosB);

void p2CollidePolygonAndCircle(CollisionData* data, const p2Shape* polygonA, const p2Vec2& bodyPosA, const p2Shape* circleB, const p2Vec2& bodyPosB);

void p2CollidePolygons(CollisionData* data, const p2Shape* polygonA, const p2Vec2& bodyPosA, const p2Shape* polygonB, const p2Vec2& bodyPosB);

void p2CollideEdgeAndCircle(CollisionData* data, const p2Shape* edgeA, const p2Vec2& bodyPosA, const p2Shape* circleB, const p2Vec2& bodyPosB);

void p2CollideEdgeAndPolygon(CollisionData* data, const p2Shape* edgeA, const p2Vec2& bodyPosA, const p2Shape* polygonB, const p2Vec2& bodyPosB);

