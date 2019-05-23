#pragma once
#include <vector>
#include "Tobes.h"

class SceneWindow
{
public:
	SceneWindow();
	void Draw();

	Tobes::GameObject* currentObject;

private:
	Tobes::Scene* m_scene;
};