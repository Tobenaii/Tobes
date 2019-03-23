#include "TestApp.h"
#include <iostream>
#include <glm/common.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/rotate_vector.hpp>

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
	Light* light = new Light();
	light->m_colour = glm::vec3(1.0f,1.0f,1.0f);
	light->m_ambientStrength = 0.1f;
	light->m_position = glm::vec3(0.0f, 2.f, -1.f);
	m_scene->AddLight(light);
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
	m_camera->SetForward(glm::rotate(m_camera->GetForward(), (float)Input::GetInstance()->GetMouseDeltaX() * dt, m_camera->GetLocalUp()));
	m_camera->SetForward(glm::rotate(m_camera->GetForward(), (float)Input::GetInstance()->GetMouseDeltaY() * dt, -m_camera->GetRight()));
}

void TestApp::Draw()
{
	m_scene->Draw(m_renderer, m_camera);
}


