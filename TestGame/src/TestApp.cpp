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
	light1->m_colour = Vector3(1.f,1.f,1.f);
	light1->m_ambientStrength = 0.3f;
	light1->m_position = Vector3(0.f, 0.f,-10.f);
	m_scene->AddLight(light1);

	m_soulspear = new Model();
	m_soulspear->LoadModel(".\\content\\art\\soulspear.tbs");
	m_scene->AddGameObject(m_soulspear);
}

void TestApp::Update(float dt)
{
	//if (Input::GetInstance()->IsKeyDown(KeyCode_W))
	//	m_camera->Translate(m_camera->GetForward() * dt * 10);
	//if (Input::GetInstance()->IsKeyDown(KeyCode_S))
	//	m_camera->Translate(m_camera->GetForward() * -dt * 10);
	//if (Input::GetInstance()->IsKeyDown(KeyCode_D))
	//	m_camera->Translate(m_camera->GetRight() * dt * 10);
	//if (Input::GetInstance()->IsKeyDown(KeyCode_A))
	//	m_camera->Translate(m_camera->GetRight() * -dt * 10);
	//if (Input::GetInstance()->IsKeyDown(KeyCode_SPACE))
	//	m_camera->Translate(Vector3(0,1,0) * dt * 10);
	//if (Input::GetInstance()->IsKeyDown(KeyCode_LEFT_SHIFT))
	//	m_camera->Translate(Vector3(0,1,0) * -dt * 10);

	//m_camera->Rotate(m_camera->GetRight(), Input::GetInstance()->GetMouseDeltaY() * dt * -0.01f);
	//m_camera->Rotate(Vector3(0,1,0), Input::GetInstance()->GetMouseDeltaX() * dt * -0.01f);
}

void TestApp::Draw()
{
	m_scene->Draw(m_renderer, m_camera);
}


