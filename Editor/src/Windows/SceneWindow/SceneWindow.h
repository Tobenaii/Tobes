#pragma once
#include <vector>
#include "Tobes.h"

class SceneWindow
{
public:
	SceneWindow();
	void Draw();

private:
	Tobes::Scene* m_scene;
};