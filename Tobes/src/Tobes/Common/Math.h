#pragma once
#include <math.h>

struct Vector3
{
	Vector3() :x(0), y(0), z(0) {}
	Vector3(float x_, float y_, float z_) : x(x_), y(y_), z(z_){}

	float x, y, z;
};

struct p2Vec4
{
	p2Vec4() : x(0), y(0), z(0), w(0) {}
	p2Vec4(float x_, float y_, float z_, float w_) { x = x_; y = y_; z = z_; w = w_; }
	void Set(float x_, float y_, float z_, float w_) { x = x_; y = y_; z = z_; w = w_; }

	float x, y, z, w;
};
