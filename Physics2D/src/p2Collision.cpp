#include "p2Collision.h"
#include "p2Fixture.h"
#include <vector>
#include <iostream>

fn collisionsFunctionArray[] = 
{
p2CollideCircles, //0 + 0 =  0
p2CollidePolygonAndCircle, //1 + 0 = 1
p2CollidePolygons, //1 + 1 = 2
p2CollideEdgeAndCircle, //3 + 0 = 3
p2CollideEdgeAndPolygon, //3 + 1 = 4
};

void CheckCollisions(const std::vector<p2Fixture*>& fixtures)
{
	int fixtureCount = fixtures.size();
	for (int f1 = 0; f1 < fixtureCount - 1; f1++)
	{
		for (int f2 = f1 + 1; f2 < fixtureCount; f2++)
		{
			int collisionId = fixtures[f1]->GetShape()->GetShapeID() + fixtures[f2]->GetShape()->GetShapeID();
			collisionsFunctionArray[collisionId](fixtures[f1]->GetShape(), fixtures[f1]->GetBodyPos(), fixtures[f2]->GetShape(), fixtures[f2]->GetBodyPos());
		}
	}
}

bool p2CollideCircles(const p2Shape* circleA, const p2Vec2& bodyPosA, const p2Shape * circleB, const p2Vec2& bodyPosB)
{
	const p2CircleShape* cA = dynamic_cast<const p2CircleShape*>(circleA);
	const p2CircleShape* cB = dynamic_cast<const p2CircleShape*>(circleB);

	p2Vec2 diff = (bodyPosA + cB->m_pos) - (bodyPosB + cA->m_pos);
	float length = p2Length(diff);
	float intersect = cA->m_radius + cB->m_radius - length;

	if (intersect > 0)
	{
		//TODO: Resolve collision
		std::cout << "COLLISION!" << std::endl;
		return true;
	}
}

bool p2CollidePolygonAndCircle(const p2Shape * polygonA, const p2Vec2& bodyPosA, const p2Shape * circleB, const p2Vec2& bodyPosB)
{
	return false;
}

bool p2CollidePolygons(const p2Shape * polygonA, const p2Vec2& bodyPosA, const p2Shape * polygonB, const p2Vec2& bodyPosB)
{
	return false;
}

bool p2CollideEdgeAndCircle(const p2Shape * edgeA, const p2Vec2& bodyPosA, const p2Shape * circleB, const p2Vec2& bodyPosB)
{
	const p2EdgeShape* eA = dynamic_cast<const p2EdgeShape*>(edgeA);
	if (!eA)
	{
		p2CollideEdgeAndCircle(circleB, bodyPosB, edgeA, bodyPosA);
		return false;
	}
	const p2CircleShape* cB = dynamic_cast<const p2CircleShape*>(circleB);

	p2Vec2 bPos = bodyPosB + cB->m_pos;
	p2Vec2 lineDirNorm = eA->Getp2() - eA->Getp1();
	float lineLength = p2Length(lineDirNorm);
	lineDirNorm /= p2Length(lineDirNorm);
	p2Vec2 startToCircle = bPos - eA->Getp1();
	float proj = p2Dot(startToCircle, lineDirNorm);
	p2Vec2 closestPoint;
	if (proj > lineLength)
		closestPoint = eA->Getp2();
	else if (proj < 0)
		closestPoint = eA->Getp1();
	else
		closestPoint = (eA->Getp1() + (lineDirNorm * proj));

	if (p2Length(closestPoint - bPos) < cB->m_radius)
	{
		std::cout << "CIRCLE COLLIDING WITH AN EDGE AWOOOOO!!!!!!" << std::endl;
		return true;
	}
	return false;
}

bool p2CollideEdgeAndPolygon(const p2Shape * edgeA, const p2Vec2& bodyPosA, const p2Shape * polygonB, const p2Vec2& bodyPosB)
{
	return false;
}
