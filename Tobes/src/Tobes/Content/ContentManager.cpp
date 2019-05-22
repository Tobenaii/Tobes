#include "ContentManager.h"
#include <filesystem>
#include <fstream>
#include <iterator>
#include "ModelFile.h"

namespace Tobes
{
	const char* ContentManager::m_supportedModelTypes[4] = { ".FBX", ".fbx", ".obj", ".tbs" };
	const char* ContentManager::m_supportedImageTypes[3] = { ".png", ".jpg", ".tga" };

	std::string ContentManager::LoadFile(std::string filePath)
	{
		std::filesystem::path p = filePath;
		if (CheckModelFile(filePath))
		{
			m_fileName = p.replace_extension(".tbs").string();
			m_fileName = p.filename().string();
			m_file = new ModelFile();
			m_file->LoadFile(filePath);
			return m_fileName;
		}
		return "";
	}

	void ContentManager::SaveFile(std::string path)
	{
		if (!m_file)
			return;
		m_file->GetData();
		//Save data buffer to file
		std::vector<std::string>* data = m_file->GetData();
		std::ofstream file(path, std::ios::out | std::ios::binary);
		std::ostream_iterator<std::string> iterator(file, "\n");
		std::copy(data->begin(), data->end(), iterator);
		file.close();
		delete m_file;
	}
	bool ContentManager::CheckModelFile(std::string path)
	{
		std::filesystem::path p = path;

		//Check if file type is a supported model type
		for (std::string s : m_supportedModelTypes)
		{
			std::string e = p.extension().string();
			if (e == s)
			{
				return true;
			}
		}
		return false;
	}
	TOBES_API bool ContentManager::CheckImageFile(std::string path)
	{
		std::filesystem::path p = path;

		//Check if file type is a supported model type
		for (std::string s : m_supportedImageTypes)
		{
			std::string e = p.extension().string();
			if (e == s)
			{
				return true;
			}
		}
		return false;
	}
}