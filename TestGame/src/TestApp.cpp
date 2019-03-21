#include "TestApp.h"
#include <iostream>
#include <glm/common.hpp>

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

	Material* material = new Material();
	material->LoadDiffuseMap("D:\\Dev\\Projects\\Tobes\\Tobes\\TestGame\\content\\art\\soulspear_diffuse.tga");

	m_soulspear = new GameObject(glm::vec3(0, 0, 0));
	m_soulspear->LoadModel("D:\\Dev\\Projects\\Tobes\\Tobes\\TestGame\\content\\art\\soulspear.tbs");
	m_soulspear->SetGlobalMaterial(material);

	m_scene->AddGameObject(m_soulspear);
}

void TestApp::Update(float dt)
{
	m_soulspear->Rotate();
}

void TestApp::Draw()
{
	m_scene->Draw(m_renderer, m_camera);
}


