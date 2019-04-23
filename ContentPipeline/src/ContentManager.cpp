#include "ContentManager.h"
#include <filesystem>
#include <fstream>
#include <iterator>
#include "ModelFile.h"
#include "ImageFile.h"

void ContentManager::LoadFile(std::string filePath)
{
	std::filesystem::path p = filePath;
	//Check if file type is a supported image type
	for (std::string s : m_supportedImageTypes)
	{
		std::string e = p.extension().string();
		if (e == s)
		{
			m_fileName = p.replace_extension(".tbs").string();
			m_file = new ImageFile();
			m_file->LoadFile(filePath);
			return;
		}
	}

	//Check if file type is a supported model type
	for (std::string s : m_supportedModelTypes)
	{
		std::string e = p.extension().string();
		if (e == s)
		{
			m_fileName = p.replace_extension(".tbs").string();
			m_file = new ModelFile();
			m_file->LoadFile(filePath);
			return;
		}
	}
}

void ContentManager::SaveFile()
{
	if (!m_file)
		return;
	//Save data buffer to file
	std::vector<std::string>* data = m_file->GetData();
	std::ofstream file(m_fileName, std::ios::out | std::ios::binary);
	std::ostream_iterator<std::string> iterator(file, "\n");
	std::copy(data->begin(), data->end(), iterator);
	file.close();
}
