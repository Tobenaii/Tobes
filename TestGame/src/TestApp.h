#pragma once
#include <Tobes.h>

class TestApp : public Tobes::Application
{
public:
	TestApp();
	~TestApp();
	virtual void Update(float dt);
	virtual void Draw();
	virtual void Startup();
	GameObject* obj;
	Vertex* vertices;
	unsigned int* indices;
};

