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

	light1 = new Light();
	light1->m_colour = glm::vec3(0.f,1.f,.5f);
	light1->m_ambientStrength = 0.3f;
	light1->m_position = glm::vec3(0.0f, 2.f, -1.f);
	m_scene->AddLight(light1);

	light2 = new Light();
	light2->m_colour = glm::vec3(1.f, 0.f, .5f);
	light2->m_ambientStrength = 0.3f;
	light2->m_position = glm::vec3(0.0f, 2.f, 1.f);
	m_scene->AddLight(light2);

	Material* material = new Material();
	material->LoadDiffuseMap(".\\content\\art\\soulspear_diffuse.tga");

	m_soulspear = new GameObject();
	m_soulspear->LoadModel(".\\content\\art\\soulspear.tbs");
	m_soulspear->SetGlobalMaterial(material);

	m_soulspear->SetPosition(glm::vec3(0, 0, 0));

	Material* lampMat = new Material();
	lampMat->LoadDiffuseMap(".\\content\\art\\Lamp.jpg");

	lamp1 = new GameObject();
	lamp1->LoadModel(".\\content\\art\\Lamp.tbs");
	lamp1->SetGlobalMaterial(lampMat);

	lamp2 = new GameObject();
	lamp2->LoadModel(".\\content\\art\\Lamp.tbs");
	lamp2->SetGlobalMaterial(lampMat);

	lamp1->Rotate(glm::vec3(1.f, 0.f, 0.f), 90.f);
	lamp2->Rotate(glm::vec3(1.f, 0.f, 0.f), 90.f);

	m_scene->AddGameObject(m_soulspear);
	m_scene->AddGameObject(lamp1);
	m_scene->AddGameObject(lamp2);
}

void TestApp::Update(float dt)
{
	timer += dt * 0.5f;
	timer2 += dt;

	if (Input::GetInstance()->IsKeyDown(KeyCode_W))
		m_camera->SetPosition(m_camera->GetPosition() + m_camera->GetForward() * dt);
	if (Input::GetInstance()->IsKeyDown(KeyCode_S))
		m_camera->SetPosition(m_camera->GetPosition() - m_camera->GetForward() * dt);
	if (Input::GetInstance()->IsKeyDown(KeyCode_D))
		m_camera->SetPosition(m_camera->GetPosition() + m_camera->GetRight() * dt);
	if (Input::GetInstance()->IsKeyDown(KeyCode_A))
		m_camera->SetPosition(m_camera->GetPosition() - m_camera->GetRight() * dt);
	m_camera->SetForward(glm::rotate(m_camera->GetForward(), (float)Input::GetInstance()->GetMouseDeltaX() * dt * 0.1f, m_camera->GetLocalUp()));
	m_camera->SetForward(glm::rotate(m_camera->GetForward(), (float)Input::GetInstance()->GetMouseDeltaY() * dt * 0.1f, -m_camera->GetRight()));

	glm::vec3 pos1 = glm::vec3(glm::sin(timer), 2.f, glm::cos(timer));
	glm::vec3 pos2 = glm::vec3(-glm::sin(timer2), 2.f, -glm::cos(timer2));
	light1->m_position = pos1 * 3.f;
	light2->m_position = pos2 * 3.f;

	lamp1->SetPosition(pos1 + glm::vec3(0, 4, 0));
	lamp2->SetPosition(pos2 + glm::vec3(0, 4, 0));
}

void TestApp::Draw()
{
	m_scene->Draw(m_renderer, m_camera);
}


