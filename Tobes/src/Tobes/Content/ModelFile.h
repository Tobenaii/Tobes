#pragma once
#include "File.h"
#include "Tobes/Core.h"

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
		TOBES_API ~ModelFile();
	};
}
