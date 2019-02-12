#pragma once
#include "p2CircleShape.h"
#include "p2PolygonShape.h"
#include "p2EdgeShape.h"
#include <vector>

class p2Fixture;

//Circle = 0
//Polygon = 1
//Edge = 3

typedef bool(*fn)(const p2Shape*, const p2Vec2&, const p2Shape*, const p2Vec2&);

extern fn collisionsFunctionArray[5];

void CheckCollisions(const std::vector<p2Fixture*>& fixtures);

bool p2CollideCircles(const p2Shape* circleA, const p2Vec2& bodyPosA, const p2Shape* circleB, const p2Vec2& bodyPosB);

bool p2CollidePolygonAndCircle(const p2Shape* polygonA, const p2Vec2& bodyPosA, const p2Shape* circleB, const p2Vec2& bodyPosB);

bool p2CollidePolygons(const p2Shape* polygonA, const p2Vec2& bodyPosA, const p2Shape* polygonB, const p2Vec2& bodyPosB);

bool p2CollideEdgeAndCircle(const p2Shape* edgeA, const p2Vec2& bodyPosA, const p2Shape* circleB, const p2Vec2& bodyPosB);

bool p2CollideEdgeAndPolygon(const p2Shape* edgeA, const p2Vec2& bodyPosA, const p2Shape* polygonB, const p2Vec2& bodyPosB);

