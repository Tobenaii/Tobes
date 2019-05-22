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
		ImGui::Button(m_scene->GetGameObject(i)->GetName().c_str());
	}
	ImGui::End();
}
