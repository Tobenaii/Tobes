#pragma once
#include <string>
#include "Tobes/Core.h"

namespace Tobes
{
	class File;
	class ContentManager
	{
		friend class Model;
	public:
		void SaveFile();
		TOBES_API static bool CheckModelFile(std::string path);
		TOBES_API static bool CheckImageFile(std::string path);

	private:
		File* m_file;
		static const char* m_supportedImageTypes[3];
		static const char* m_supportedModelTypes[4];
		std::string m_fileName;

	private:
		std::string LoadFile(std::string filePath);
	};
}
