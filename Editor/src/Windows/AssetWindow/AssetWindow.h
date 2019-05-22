#pragma once
#include <vector>
#include "Tobes.h"
#include "Folder.h"

class AssetWindow
{
public:
	AssetWindow();
	void OnFileDrop(int count, const char ** paths);
	void Draw();
	void ChangeFolder(Folder* folder);
	static Tobes::ContentManager contentManager;

private:
	std::vector<Tobes::Mesh*> m_meshes;
	Folder m_baseFolder = Folder(nullptr, "Assets", "Assets", this);
	Folder* m_currentFolder;
};