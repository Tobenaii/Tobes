#include "Light.h"
#include "Tobes/Common/Scene.h"

void Tobes::Light::Start()
{
	m_scene->AddLight(this);
}
