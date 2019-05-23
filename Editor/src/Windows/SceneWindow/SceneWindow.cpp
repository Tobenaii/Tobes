#include "SceneWindow.h"
#include "Tobes/Application.h"
#include <iostream>

SceneWindow::SceneWindow()
{
	m_scene = Tobes::Application::GetCurrentScene();
}

void SceneWindow::Draw()
{
	ImGui::Begin("Scene");
	if (ImGui::BeginDragDropTarget())
	{
		if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("DRAG_ASSET_FILE"))
		{
			std::string file((const char*)payload->Data, payload->DataSize);
			m_scene->LoadModel(file);
		}
		ImGui::EndDragDropTarget();
	}
	for (int i = 0; i < m_scene->GetGameObjectCount(); i++)
	{
		Tobes::GameObject* parent = m_scene->GetGameObject(i);
		if (parent->GetChildCount() > 0)
		{
			if (ImGui::CollapsingHeader(parent->GetName().c_str()))
			{
				ImGui::Indent();
				for (int i = 0; i < parent->GetChildCount(); i++)
				{
					Tobes::GameObject* child = parent->GetChild(i);
					ImGui::Button(child->GetName().c_str());
				}
				ImGui::Unindent();
			}
		}
		else
			ImGui::Button(parent->GetName().c_str());
	}
	ImGui::End();
}
