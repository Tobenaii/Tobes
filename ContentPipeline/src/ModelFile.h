#pragma once
#include "File.h"
struct aiScene;
class ModelFile : public File
{
private:
	const aiScene* m_scene;
	virtual void LoadFile(std::string filePath);
	virtual std::vector<float>* GetRawBytes();
	std::vector<float>* m_dataBuffer;
	int m_dataBufferSize;
	~ModelFile();
};
