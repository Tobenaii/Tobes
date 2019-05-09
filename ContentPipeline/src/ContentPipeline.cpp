#include "ContentPipeline.h"
#include <iostream>

Tobes::Application* CreateApplication()
{
	return new ContentPipeline();
}

void ContentPipeline::Startup()
{
	Tobes::Light* light = new Tobes::Light();
	light->ambientStrength = 0.3f;
	light->colour = Vector3(1, 1, 1);
	light->direction = Vector3(0, 0, 1);
	light->position = Vector3(0, 0, -100);
}

void ContentPipeline::OnFileDrop(int count, const char ** paths)
{
	for (int i = 0; i < count; i++)
	{
		if (Tobes::ContentManager::CheckModelFile(paths[i]))
		{
			if (m_currentModel != nullptr)
			{
				m_scene->RemoveGameObject(m_currentModel);
			}
			std::cout << "Loading model: " << paths[i] << std::endl;
			m_currentModel = new Tobes::Model();
			m_currentModel->LoadModel(paths[i]);
			m_scene->AddGameObject(m_currentModel);

			m_meshBools.clear();
			m_meshBools.shrink_to_fit();
			for (int i = 0; i < m_currentModel->GetMeshCount(); i++)
			{
				m_meshBools.push_back(false);
				m_materials.push_back(new Tobes::Material());
				m_currentModel->SetMeshMaterial(i, m_materials[i]);
			}
		}
		else if (Tobes::ContentManager::CheckImageFile(paths[i]))
		{
			m_textures.push_back(new Tobes::Texture(paths[i]));
		}
	}
}

void ContentPipeline::Draw()
{
	ImGui::Begin("Meshes: ");
	if (m_currentModel != nullptr)
	{
		for (int i = 0; i < m_currentModel->GetMeshCount(); i++)
		{
			ImGui::RadioButton(m_currentModel->GetMesh(i)->GetName().c_str(), m_meshBools[i]);
			if (ImGui::IsItemClicked())
			{
				m_meshBools[i] = !m_meshBools[i];
			}
		}
	}
	ImGui::End();
	ImGui::Begin("Textures: ");
	for (Tobes::Texture* texture : m_textures)
	{
		ImGui::ImageButton((ImTextureID)texture->GetTextureID(), { 50,50 });
		if (ImGui::IsItemClicked())
		{
			for (int i = 0; i < m_meshBools.size(); i++)
			{
				if (!m_meshBools[i])
					continue;
				m_materials[i]->SetDiffuseMap(texture);
			}
		}

	}
	ImGui::End();
	m_scene->Draw(m_renderer, m_camera);
}

void ContentPipeline::Update(float dt)
{
	Tobes::Input* input = Tobes::Input::GetInstance();
	if (m_currentModel == nullptr)
		return;
	double scroll = input->GetScrollDeltaY();
	if (scroll != 0)
		m_currentModel->Translate(Vector3(0, 0, (float)scroll));

	float mouseDeltaX = (float)input->GetMouseDeltaX();
	float mouseDeltaY = (float)input->GetMouseDeltaY();

	if (input->IsButtonDown(0))
	{
		if (mouseDeltaX != 0)
			m_currentModel->Rotate(Vector3(0, 1, 0), mouseDeltaX * dt * 0.5f);
		if (mouseDeltaY != 0)
			m_currentModel->Rotate(Vector3(1, 0, 0), mouseDeltaY * dt * 0.5f);
	}

	if (input->IsButtonDown(1))
	{
		m_currentModel->Translate(Vector3(input->GetMouseDeltaX() * dt, input->GetMouseDeltaY() * dt, 0));
	}
}
