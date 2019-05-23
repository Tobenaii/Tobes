#pragma once
#include "Tobes.h"


class GameWindow
{
public:
	void Draw();
	void UpdateCamera(Tobes::Camera* m_camera, float dt);
};
