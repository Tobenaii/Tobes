#pragma once
#include "Tobes.h"
#include <windows.h>
class AssetWindow;

struct File
{
	File(std::string n, std::string fp)
	{
		name = n;
		fullPath = fp;
	}
	std::string name;
	std::string fullPath;
};

class Folder
{
public:
	Folder(Folder* parent, std::string name,
			std::string fullPath, AssetWindow* assetWindow)
			: m_name(name), m_fullPath(fullPath),
		m_parent(parent), m_assetWindow(assetWindow) {
		CreateDirectory(fullPath.c_str(), NULL);
	}

	void AddFolder(std::string name);
	void AddFile(std::string filePath);
	std::string GetName() { return m_name; }
	std::string GetFullPath() { return m_fullPath; }
	void Draw();

private:
	std::vector<File> m_files;
	std::vector<Folder*> m_children;
	Folder* m_parent;
	std::string m_fullPath;
	std::string m_name;
	static Tobes::Texture* m_folderIcon;
	AssetWindow* m_assetWindow;
};
