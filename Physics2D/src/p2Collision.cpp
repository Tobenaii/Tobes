#include "p2Collision.h"
#include <vector>
#include <iostream>
#include "p2Body.h"
fn collisionsFunctionArray[] = 
{
p2CollideCircles, //0 + 0 =  0
p2CollidePolygonAndCircle, //1 + 0 = 1
p2CollidePolygons, //1 + 1 = 2
p2CollideEdgeAndCircle, //3 + 0 = 3
p2CollideEdgeAndPolygon, //3 + 1 = 4
};

void ResolveCollision(const CollisionData& data)
{
	float j = (p2Dot(data.relativeVelocity * -(0.5f + 1), data.normal)) / (p2Dot(data.normal, data.normal * (1 / data.bodyA->GetMass() + 1 / data.bodyB->GetMass())));
	if (data.bodyA->GetType() != p2_kinematicBody)
		data.bodyA->SetPosition(data.bodyA->GetPosition() - (data.normal * (data.overlap / 2)));
	if (data.bodyB->GetType() != p2_kinematicBody)
		data.bodyB->SetPosition(data.bodyB->GetPosition() + (data.normal * (data.overlap / 2)));

	if (data.bodyA->GetType() == p2_kinematicBody)
		data.bodyB->SetPosition(data.bodyB->GetPosition() + (data.normal * (data.overlap / 2)));
	else if (data.bodyB->GetType() == p2_kinematicBody)
		data.bodyA->SetPosition(data.bodyA->GetPosition() - (data.normal * (data.overlap / 2)));

	data.bodyA->ApplyForce(data.normal * (j), data.point);
	data.bodyB->ApplyForce(data.normal * (j) * -1, data.point);
}

void CheckCollisions(const std::vector<p2Fixture*> fixtures)
{
	int fixtureCount = fixtures.size();
	for (int f1 = 0; f1 < fixtureCount - 1; f1++)
	{
		if (fixtures[f1] == nullptr)
			continue;
		for (int f2 = f1 + 1; f2 < fixtureCount; f2++)
		{
			if (fixtures[f2] == nullptr)
				continue;
			CollisionData data;
			int collisionId = fixtures[f1]->GetShape()->GetShapeID() + fixtures[f2]->GetShape()->GetShapeID();
			if (collisionId > 4)
				continue;
			collisionsFunctionArray[collisionId](&data, fixtures[f1]->GetShape(), fixtures[f1]->GetBodyPos(), fixtures[f2]->GetShape(), fixtures[f2]->GetBodyPos());
			//TODO: Check data for collision
			if (data.collision)
			{
				data.normal = data.normal / p2Length(data.normal);
				
				data.relativeVelocity = fixtures[f1]->GetBodyVelocity() - fixtures[f2]->GetBodyVelocity();
				data.bodyA = fixtures[f1]->GetBody();
				data.bodyB = fixtures[f2]->GetBody();
				ResolveCollision(data);
			}
		}
	}
}

void p2CollideCircles(CollisionData* data, const p2Shape* circleA, const p2Vec2& bodyPosA, const p2Shape * circleB, const p2Vec2& bodyPosB)
{
	const p2CircleShape* cA = dynamic_cast<const p2CircleShape*>(circleA);
	const p2CircleShape* cB = dynamic_cast<const p2CircleShape*>(circleB);

	p2Vec2 diff = (bodyPosB + cB->m_pos) - (bodyPosA + cA->m_pos);
	float length = p2Length(diff);
	float intersect = cA->m_radius + cB->m_radius - length;

	if (intersect > 0)
	{
		data->collision = true;
		data->normal = diff;
		p2Vec2 norm = diff / length;
		data->point = norm * cA->m_radius;
		data->overlap = intersect;
	}
}

void p2CollidePolygonAndCircle(CollisionData* data, const p2Shape * polygonA, const p2Vec2& bodyPosA, const p2Shape * circleB, const p2Vec2& bodyPosB)
{
	const p2PolygonShape* pA = dynamic_cast<const p2PolygonShape*>(polygonA);
	if (!pA)
	{
		p2CollidePolygonAndCircle(data, circleB, bodyPosB, polygonA, bodyPosA);
		return;
	}

	const p2CircleShape* cB = dynamic_cast<const p2CircleShape*>(circleB);

	for (int i = 0; i < pA->GetVertexCount() - 1; i++)
	{
		p2EdgeShape edge;
		edge.Setp1(bodyPosA + pA->GetVertex(i));
		edge.Setp2(bodyPosA + pA->GetVertex(i + 1));
		p2CollideEdgeAndCircle(data, &edge, bodyPosA, circleB, bodyPosB);
		if (data->collision)
			return;
	}

}

void p2CollidePolygons(CollisionData* data, const p2Shape * polygonA, const p2Vec2& bodyPosA, const p2Shape * polygonB, const p2Vec2& bodyPosB)
{
}

void p2CollideEdgeAndCircle(CollisionData* data, const p2Shape * edgeA, const p2Vec2& bodyPosA, const p2Shape * circleB, const p2Vec2& bodyPosB)
{
	const p2EdgeShape* eA = dynamic_cast<const p2EdgeShape*>(edgeA);
	if (!eA)
	{
		p2CollideEdgeAndCircle(data, circleB, bodyPosB, edgeA, bodyPosA);
		return;
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

	float overLap = p2Length(closestPoint - bPos);
	if (overLap < cB->m_radius)
	{
		data->collision = true;
		data->normal = bodyPosB - closestPoint;
		data->point = closestPoint;
		data->overlap = cB->m_radius - overLap;
	}
}

void p2CollideEdgeAndPolygon(CollisionData* data, const p2Shape * edgeA, const p2Vec2& bodyPosA, const p2Shape * polygonB, const p2Vec2& bodyPosB)
{
	const p2EdgeShape* eA = dynamic_cast<const p2EdgeShape*>(edgeA);
	if (!eA)
	{
		p2CollideEdgeAndPolygon(data, polygonB, bodyPosB, edgeA, bodyPosA);
		return;
	}
	const p2PolygonShape* pB = dynamic_cast<const p2PolygonShape*>(polygonB);

	for (int i = 0; i < pB->GetVertexCount(); i++)
	{
		p2EdgeShape e1;
		e1.Setp1(p2Vec2(pB->GetVertex(i)));
		e1.Setp2(p2Vec2(pB->GetVertex((i == pB->GetVertexCount() - 1)?(0):(i + 1))));

		float x1 = eA->Getp1().x;
		float x2 = eA->Getp2().x;
		float x3 = e1.Getp1().x + bodyPosB.x;
		float x4 = e1.Getp2().x + bodyPosB.x;
		float y1 = eA->Getp1().y;
		float y2 = eA->Getp2().y;
		float y3 = e1.Getp1().y + bodyPosB.y;
		float y4 = e1.Getp2().y + bodyPosB.y;

		float l1 = ((x4 - x3)*(y1 - y3) - (y4 - y3)*(x1 - x3)) / ((y4 - y3)*(x2 - x1) - (x4 - x3)*(y2 - y1));
		float l2 = ((x2 - x1)*(y1 - y3) - (y2 - y1)*(x1 - x3)) / ((y4 - y3)*(x2 - x1) - (x4 - x3)*(y2 - y1));
		if (l1 >= 0 && l1 <= 1 && l2 >= 0 && l2 <= 1)
		{
			data->collision = true;
			p2Vec2 intersection(x1 + (l1 * (x2 - x1)), y1 + (l1 * (y2 - y1)));
			data->normal = bodyPosB - intersection;
			return;
		}
	}
}
