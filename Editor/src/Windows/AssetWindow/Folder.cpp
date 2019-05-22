#include "Folder.h"
#include "AssetWindow.h"
#include <iostream>

Tobes::Texture* Folder::m_folderIcon = new Tobes::Texture("Content\\AssetWindow\\folder_icon.png");

void Folder::AddFolder(std::string name)
{
	for (Folder* folder : m_children)
	{
		if (folder->m_name == name)
			return;
	}
	m_children.emplace_back(new Folder(this, name, m_fullPath + "/" + name, m_assetWindow));
}

void Folder::AddFile(std::string filePath)
{
	if (Tobes::ContentManager::CheckModelFile(filePath))
	{
		std::string name = AssetWindow::contentManager.LoadFile(filePath);
		AssetWindow::contentManager.SaveFile(".\\" + m_fullPath + "\\" + name);
		m_files.emplace_back(name, std::string(".\\" + m_fullPath + "\\" + name));
	}

	else if (Tobes::ContentManager::CheckImageFile(filePath))
	{

	}
}

void Folder::Draw()
{
	for (Folder* folder : m_children)
	{
		ImGui::Text(folder->m_name.c_str());
		ImGui::ImageButton((ImTextureID)m_folderIcon->GetTextureID(), { 50,50 });
		if (ImGui::IsItemClicked())
		{
			m_assetWindow->ChangeFolder(folder);
			return;
		}
	}

	int id = 0;
	for (File file : m_files)
	{
		ImGui::PushID(id);
		ImGui::Text(file.name.c_str());
		ImGui::ImageButton((ImTextureID)m_folderIcon->GetTextureID(), { 50,50 });
		if (ImGui::BeginDragDropSource(ImGuiDragDropFlags_None))
		{
			ImGui::SetDragDropPayload("DRAG_ASSET_FILE", file.fullPath.c_str(), file.fullPath.size());
			ImGui::Text(file.name.c_str());
			ImGui::EndDragDropSource();
		}
		ImGui::PopID();
	}
}
