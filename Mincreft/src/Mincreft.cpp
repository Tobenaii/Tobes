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
	terrain->AddComponent<Terrain>()->Generate(100,100,100, 1, 1);

	m_camera->gameObject->AddComponent<CameraController>();
}

void Mincreft::Update(float dt)
{

}