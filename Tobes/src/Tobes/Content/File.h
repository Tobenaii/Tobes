#pragma once
#include <vector>

namespace Tobes
{
	class File
	{
		friend class ContentManager;
	protected:
		virtual void LoadFile(std::string filePath) = 0;
		std::vector<std::string>* m_dataBuffer = new std::vector<std::string>();
		virtual std::vector<std::string>* GetData() { return nullptr; }
		virtual ~File() {}
	};
}
