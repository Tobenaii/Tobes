#include "ContentManager.h"
#include <filesystem>
#include <fstream>
#include <iterator>
#include "ModelFile.h"

void ContentManager::LoadFile(std::string filePath)
{
	std::filesystem::path p = filePath;
	for (std::string s : m_supportedImageTypes)
	{
		std::string e = p.extension().string();
		if (e == s)
		{
		}
	}

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
	std::vector<float>* data = m_file->GetRawBytes();
	std::ofstream file(m_fileName, std::ios::out | std::ios::binary);
	std::ostream_iterator<float> iterator(file, "\n");
	std::copy(data->begin(), data->end(), iterator);
	file.close();
}
