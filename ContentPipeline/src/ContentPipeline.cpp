#include "ContentPipeline.h"
#include <iostream>
#include "Tobes/imgui/imgui.h"

Tobes::Application* CreateApplication()
{
	return new ContentPipeline();
}

void ContentPipeline::Startup()
{
	m_scene = new Tobes::Scene();
	Tobes::Light* light = new Tobes::Light();
	light->ambientStrength = 0.3f;
	light->colour = Vector3(1, 1, 1);
	light->direction = Vector3(0, 0, 1);
	light->position = Vector3(0, 0, -100);
	m_scene->AddLight(light);
}

void ContentPipeline::OnFileDrop(int count, const char ** paths)
{
	if (m_currentModel != nullptr)
	{
		m_scene->RemoveGameObject(m_currentModel);
	}
	std::cout << "Loading: " << paths[0] << std::endl;
	m_currentModel = new Tobes::Model();
	m_currentModel->LoadModel(paths[0]);
	m_scene->AddGameObject(m_currentModel);
}

void ContentPipeline::Draw()
{
	ImGui::Begin("Meshes: ");
	if (m_currentModel != nullptr)
	{
		for (int i = 0; i < m_currentModel->GetMeshCount(); i++)
		{
			ImGui::RadioButton(m_currentModel->GetMesh(i)->GetName().c_str(), true);
		}
	}
	ImGui::End();
	m_scene->Draw(m_renderer, m_camera);
}

void ContentPipeline::Update()
{
}
