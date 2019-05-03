#pragma once
#include "File.h"

struct aiScene;
namespace Tobes
{
	class ModelFile : public File
	{
	private:
		const aiScene* m_scene;
		virtual void LoadFile(std::string filePath);
		virtual std::vector<std::string>* GetData();
		int m_dataBufferSize;
		~ModelFile();
	};
}
