#pragma once
#include <Tobes.h>

class TestApp : public Tobes::Application
{
public:
	TestApp();
	~TestApp();
	virtual void Update(float dt);
};

