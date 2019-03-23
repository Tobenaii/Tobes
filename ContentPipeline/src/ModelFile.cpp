#include "ModelFile.h"
#include <assimp/scene.h>
#include <assimp/cimport.h>
#include <assimp/postprocess.h>
#include <chrono>
#include <iostream>

void ModelFile::LoadFile(std::string filePath)
{
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	m_scene = aiImportFile((filePath).c_str(), aiProcessPreset_TargetRealtime_MaxQuality);
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	std::cout << duration << std::endl;
}

std::vector<std::string>* ModelFile::GetData()
{
	m_dataBuffer->push_back(std::to_string(m_scene->mNumMeshes));
	aiString name;
	m_scene->mMaterials[0]->GetTexture(aiTextureType_DIFFUSE, 0, &name);
	for (int i = 0; i < m_scene->mNumMeshes; i++)
	{
		m_dataBuffer->push_back(m_scene->mMeshes[i]->mName.C_Str());
		m_dataBuffer->push_back(std::to_string(m_scene->mMeshes[i]->mNumVertices));
		aiVector3D* t = m_scene->mMeshes[i]->mTextureCoords[0];
		for (int n = 0; n < m_scene->mMeshes[i]->mNumVertices; n++)
		{
			aiVector3D v = m_scene->mMeshes[i]->mVertices[n];
			m_dataBuffer->push_back(std::to_string(v.x));
			m_dataBuffer->push_back(std::to_string(v.y));
			m_dataBuffer->push_back(std::to_string(v.z));
			if (t != NULL)
			{
				m_dataBuffer->push_back(std::to_string(t[n].x));
				m_dataBuffer->push_back(std::to_string(t[n].y));
			}
			else
			{
				m_dataBuffer->push_back(std::to_string(-1));
			}
			aiVector3D normal = m_scene->mMeshes[i]->mNormals[n];
			m_dataBuffer->push_back(std::to_string(normal.x));
			m_dataBuffer->push_back(std::to_string(normal.y));
			m_dataBuffer->push_back(std::to_string(normal.z));
		}
		unsigned int numIndices = 0;
		for (int f = 0; f < m_scene->mMeshes[i]->mNumFaces; f++)
		{
			numIndices += m_scene->mMeshes[i]->mFaces[f].mNumIndices;
		}
		m_dataBuffer->push_back(std::to_string(numIndices));
		for (int f = 0; f < m_scene->mMeshes[i]->mNumFaces; f++)
		{
			for (int in = 0; in < m_scene->mMeshes[i]->mFaces[f].mNumIndices; in++)
			{
				unsigned int index = m_scene->mMeshes[i]->mFaces[f].mIndices[in];
				m_dataBuffer->push_back(std::to_string(index));
			}
		}
	}
	return m_dataBuffer;
}

ModelFile::~ModelFile()
{
	delete m_scene;
}


