#pragma once
#include <Tobes.h>

class ContentPipeline : public Tobes::Application
{
private:
	virtual void Startup();
	virtual void OnFileDrop(int count, const char ** paths);
	virtual void Draw();
	virtual void Update();

private:
	Tobes::Scene* m_scene;
	Tobes::Model* m_currentModel;
};
