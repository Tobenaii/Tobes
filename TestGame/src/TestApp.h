#pragma once
#include <Tobes.h>
#include <Tobes/Renderer3D/Model.h>

class TestApp : public Tobes::Application
{
public:
	TestApp();
	~TestApp();
	virtual void Update(float dt);
	virtual void Draw();
	virtual void Startup();
	Model* m_soulspear;
	Model* lamp1;
	Model* lamp2;
	Scene* m_scene;
	Light* light1;
	Light* light2;

	float timer;
	float timer2;
};

