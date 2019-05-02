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
		point = Vector2(0, 0);
		overlap = 0;
	}

	bool collision;
	Vector2 relativeVelocity;
	p2Body* bodyA;
	p2Body* bodyB;
	Vector2 normal;
	Vector2 point;
	float overlap;
};

typedef void(*fn)(CollisionData*, const p2Shape*, const Vector2&, const p2Shape*, const Vector2&);

extern fn collisionsFunctionArray[5];

void ResolveCollision(const CollisionData& data);

void CheckCollisions(const std::vector<p2Fixture*> fixtures);

void p2CollideCircles(CollisionData* data, const p2Shape* circleA, const Vector2& bodyPosA, const p2Shape* circleB, const Vector2& bodyPosB);

void p2CollidePolygonAndCircle(CollisionData* data, const p2Shape* polygonA, const Vector2& bodyPosA, const p2Shape* circleB, const Vector2& bodyPosB);

void p2CollidePolygons(CollisionData* data, const p2Shape* polygonA, const Vector2& bodyPosA, const p2Shape* polygonB, const Vector2& bodyPosB);

void p2CollideEdgeAndCircle(CollisionData* data, const p2Shape* edgeA, const Vector2& bodyPosA, const p2Shape* circleB, const Vector2& bodyPosB);

void p2CollideEdgeAndPolygon(CollisionData* data, const p2Shape* edgeA, const Vector2& bodyPosA, const p2Shape* polygonB, const Vector2& bodyPosB);

