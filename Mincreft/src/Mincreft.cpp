#include "Mincreft.h"
#include "CameraController.h"
#include "Terrain/Terrain.h"

Tobes::Application* CreateApplication()
{
	return new Mincreft();
}

void Mincreft::Startup()
{
	Tobes::GameObject* terrain = new Tobes::GameObject();
	terrain->AddComponent<Terrain>()->Generate(250, 1, 250, 1, 1);

	Tobes::GameObject* light = new Tobes::GameObject();
	Tobes::Light* l = light->AddComponent<Tobes::Light>();
	l->ambientStrength = 0.3f;
	l->colour = Vector3(1, 1, 1);

	m_camera->gameObject->AddComponent<CameraController>();
}

void Mincreft::Update(float dt)
{

}