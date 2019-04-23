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
	GameObject* lamp1;
	GameObject* lamp2;
	Scene* m_scene;
	Light* light1;
	Light* light2;

	float timer;
	float timer2;
};

