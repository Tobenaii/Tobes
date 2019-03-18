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
	Shader* shader = new Shader();

	shader->LoadVertexShader("H:\\Dev\\Projects\\Tobes\\Tobes\\TestGame\\content\\shaders\\vertex.txt");
	shader->LoadFragmentShader("H:\\Dev\\Projects\\Tobes\\Tobes\\TestGame\\content\\shaders\\frag.txt");
	shader->LinkProgram();
	obj = new GameObject(glm::vec3(0, 0, 0));

	obj->SetShader(shader);

	Mesh* mesh = new Mesh("C:\\Users\\Tobenai\\Downloads\\soulspear\\soulspear\\soulspear.tbs");
	obj->SetMesh(mesh);
}

void TestApp::Update(float dt)
{

	std::cout << dt << std::endl;
	m_camera->SetPosition(m_camera->GetPosition() + glm::vec3(-0.1f,0,0) * dt);
}

void TestApp::Draw()
{
	obj->Draw(m_renderer, m_camera);
}


