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

	vertices = new Vertex[4]{
		Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)),
		Vertex(glm::vec3(0.5f, -0.5f, 0.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)),
		Vertex(glm::vec3(0.5f, 0.5f, 0.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)),
		Vertex(glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)),
	};

	indices = new unsigned int[6]{
		0,1,2,
		2,3,0
	};

	Mesh* mesh = new Mesh("H:\\Dev\\Projects\\Tobes\\Tobes\\ContentPipeline\\Content\\advancedCharacter.tbs");
	obj->SetMesh(mesh);
}

void TestApp::Update(float dt)
{
	//m_camera->SetPosition(m_camera->GetPosition() + glm::vec3(-1,0,0) * dt);
}

void TestApp::Draw()
{
	obj->Draw(m_renderer, m_camera);
}


