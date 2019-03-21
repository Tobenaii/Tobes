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
	GameObject* m_soulspear;
	Scene* m_scene;
};

