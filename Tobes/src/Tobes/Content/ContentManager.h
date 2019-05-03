#pragma once
#include <string>

namespace Tobes
{
	class File;

	class ContentManager
	{
	public:
		std::string LoadFile(std::string filePath);
		void SaveFile();

	private:
		File* m_file;
		const std::string m_supportedImageTypes[3]{ ".png", ".jpg", ".tga" };
		const std::string m_supportedModelTypes[3]{ ".obj", ".fbx", ".FBX" };
		std::string m_fileName;
	};
}
