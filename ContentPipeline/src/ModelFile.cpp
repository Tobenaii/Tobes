#include "ModelFile.h"
#include <assimp/scene.h>
#include <assimp/cimport.h>
#include <assimp/postprocess.h>

void ModelFile::LoadFile(std::string filePath)
{
	m_scene = aiImportFile((filePath).c_str(), aiProcessPreset_TargetRealtime_MaxQuality);
}

std::vector<float>* ModelFile::GetRawBytes()
{
	delete m_dataBuffer;
	m_dataBuffer = new std::vector<float>();
	m_dataBuffer->push_back(m_scene->mNumMeshes);
	for (int i = 0; i < m_scene->mNumMeshes; i++)
	{
		//How many components
		m_dataBuffer->push_back(m_scene->mMeshes[i]->mNumVertices);
		for (int n = 0; n < m_scene->mMeshes[i]->mNumVertices; n++)
		{
			aiVector3D v = m_scene->mMeshes[i]->mVertices[n];
			m_dataBuffer->push_back(v.x);
			m_dataBuffer->push_back(v.y);
			m_dataBuffer->push_back(v.z);
			m_dataBufferSize += sizeof(float) * 3;
		}
		int indices = 0;
		for (int f = 0; f < m_scene->mMeshes[i]->mNumFaces; f++)
		{
			for (int in = 0; in < m_scene->mMeshes[i]->mFaces[f].mNumIndices; in++)
			{
				indices++;
			}
		}
		m_dataBuffer->push_back(indices);
		for (int f = 0; f < m_scene->mMeshes[i]->mNumFaces; f++)
		{
			for (int in = 0; in < m_scene->mMeshes[i]->mFaces[f].mNumIndices; in++)
			{
				unsigned int index = m_scene->mMeshes[i]->mFaces[f].mIndices[in];
				m_dataBuffer->push_back(index);
				m_dataBufferSize += sizeof(unsigned int);
			}
		}
	}
	return m_dataBuffer;
}

ModelFile::~ModelFile()
{
	delete m_scene;
}


