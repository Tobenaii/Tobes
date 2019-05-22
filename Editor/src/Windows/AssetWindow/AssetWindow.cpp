#include "AssetWindow.h"

Tobes::ContentManager AssetWindow::contentManager = Tobes::ContentManager();

AssetWindow::AssetWindow()
{
	m_currentFolder = &m_baseFolder;
}

void AssetWindow::OnFileDrop(int count, const char ** paths)
{
	for (int i = 0; i < count; i++)
	{
		m_currentFolder->AddFile(paths[i]);
	}
}

void AssetWindow::Draw()
{
	static bool merpaderp = false;
	static char merp[128] = "New Folder";

	ImGui::Begin(m_currentFolder->GetFullPath().c_str());
	ImGui::Button("Create Folder");
	if (ImGui::IsItemClicked())
	{
		if (merpaderp)
			m_currentFolder->AddFolder(merp);
		else
			merpaderp = true;
	}
	if (merpaderp)
		ImGui::InputText("Folder Name", merp, 128);
	m_currentFolder->Draw();
	ImGui::End();
}

void AssetWindow::ChangeFolder(Folder* folder)
{
	m_currentFolder = folder;
}
