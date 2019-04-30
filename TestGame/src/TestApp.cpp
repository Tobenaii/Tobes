#include "TestApp.h"
#include <iostream>
#include <Tobes/Common/Math/Vector3.h>

Tobes::Application* Tobes::CreateApplication()
{
	return new TestApp();
}

TestApp::TestApp()
{
}

TestApp::~TestApp()
{
}

void TestApp::Startup()
{
	m_scene = new Scene();

	light1 = new Light();
	light1->m_colour = Vector3(0.f, 1.f, .5f);
	light1->m_ambientStrength = 0.3f;
	light1->m_position = Vector3(0.0f, 2.f, -1.f);
	m_scene->AddLight(light1);

	light2 = new Light();
	light2->m_colour = Vector3(1.f, 0.f, .5f);
	light2->m_ambientStrength = 0.3f;
	light2->m_position = Vector3(0.0f, 2.f, 1.f);
	m_scene->AddLight(light2);

	Material* material = new Material();
	material->LoadDiffuseMap(".\\content\\art\\soulspear_diffuse.tga");

	m_soulspear = new GameObject();
	m_soulspear->LoadModel(".\\content\\art\\soulspear.tbs");
	m_soulspear->SetGlobalMaterial(material);

	m_soulspear->SetPosition(Vector3(0, 0, 0));

	Material* lampMat = new Material();
	lampMat->LoadDiffuseMap(".\\content\\art\\Lamp.jpg");

	lamp1 = new GameObject();
	lamp1->LoadModel(".\\content\\art\\Lamp.tbs");
	lamp1->SetGlobalMaterial(lampMat);

	lamp2 = new GameObject();
	lamp2->LoadModel(".\\content\\art\\Lamp.tbs");
	lamp2->SetGlobalMaterial(lampMat);

	m_scene->AddGameObject(m_soulspear);
	m_scene->AddGameObject(lamp1);
	m_scene->AddGameObject(lamp2);
}

void TestApp::Update(float dt)
{
	if (Input::GetInstance()->IsKeyDown(KeyCode_W))
		m_camera->SetPosition(m_camera->GetPosition() + m_camera->GetForward() * dt);
	if (Input::GetInstance()->IsKeyDown(KeyCode_S))
		m_camera->SetPosition(m_camera->GetPosition() - m_camera->GetForward() * dt);
	if (Input::GetInstance()->IsKeyDown(KeyCode_D))
		m_camera->SetPosition(m_camera->GetPosition() + m_camera->GetRight() * dt);
	if (Input::GetInstance()->IsKeyDown(KeyCode_A))
		m_camera->SetPosition(m_camera->GetPosition() - m_camera->GetRight() * dt);
}

void TestApp::Draw()
{
	m_scene->Draw(m_renderer, m_camera);
}


