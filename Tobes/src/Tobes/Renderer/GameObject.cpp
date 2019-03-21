#include "GameObject.h"
#include <glm/common.hpp>
#include <glm/ext.hpp>
#include <glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <string>
#include <iostream>
#include <chrono>

GameObject::GameObject()
{
	m_translationMatrix = glm::mat4(1.0f);
	m_scaleMatrix = glm::mat4(1.0f);
	m_rotationMatrix = glm::mat4(1.0f);
	m_modelMatrix = m_translationMatrix * m_rotationMatrix * m_scaleMatrix;
}

GameObject::GameObject(glm::vec3 position)
{
	m_translationMatrix = glm::translate(glm::mat4(1.0f), position);
	m_scaleMatrix = glm::mat4(1.0f);
	m_rotationMatrix = glm::mat4(1.0f);
	m_modelMatrix = m_translationMatrix * m_rotationMatrix * m_scaleMatrix;
}

glm::mat4 GameObject::GetModelMatrix()
{
	return m_modelMatrix;
}

void GameObject::LoadModel(std::string path)
{
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	std::ifstream buffer(path, std::ios::in | std::ios::binary);

	unsigned int meshCount;
	std::string line;
	if (buffer.is_open())
	{
		std::getline(buffer, line);
		meshCount = stof(line);
		for (int m = 0; m < meshCount; m++)
		{
			unsigned int vertexCount;
			Vertex* vertexData;
			std::string meshName;
			std::getline(buffer, line);
			meshName = line;
			std::getline(buffer, line);
			vertexCount = stof(line);
			vertexData = new Vertex[vertexCount];
			for (int i = 0; i < vertexCount; i++)
			{
				glm::vec4 pos;
				std::getline(buffer, line);
				pos.x = stof(line);
				std::getline(buffer, line);
				pos.y = stof(line);
				std::getline(buffer, line);
				pos.z = stof(line);
				pos.w = 1.0f;
				glm::vec2 texCoord;
				std::getline(buffer, line);
				if (stof(line) != -1)
				{
					texCoord.x = stof(line);
					std::getline(buffer, line);
					texCoord.y = stof(line);
				}
				else
					texCoord = glm::vec2(0, 0);
				glm::vec3 norm;
				std::getline(buffer, line);
				norm.x = stof(line);
				std::getline(buffer, line);
				norm.y = stof(line);
				std::getline(buffer, line);
				norm.z = stof(line);
				vertexData[i].position = pos;
				vertexData[i].textureCoord = texCoord;
				vertexData[i].normal = norm;
			}
			std::getline(buffer, line);
			unsigned int indexCount;
			unsigned int* indices;
			indexCount = stof(line);
			indices = new unsigned int[indexCount];
			for (int i = 0; i < indexCount; i++)
			{
				std::getline(buffer, line);
				indices[i] = stof(line);
			}
			Mesh* mesh = new Mesh(vertexData, vertexCount, indices, indexCount);
			m_meshes.insert(std::pair<std::string, Mesh*>(meshName, mesh));
			mesh->SetData();
		}
	}
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	std::cout << duration << std::endl;
}


void GameObject::Draw(Renderer * renderer, Camera* camera)
{
	for (const auto& it : m_meshes)
	{
		if (it.second->m_material->m_shader)
		{
			it.second->m_material->m_shader->ApplyShader();
			glm::mat4 mvp = camera->GetProjection() * camera->GetView() * m_modelMatrix;
			it.second->m_material->m_shader->SetUniformMat4("MVP", mvp);
		}
		if (it.second->m_material->m_diffuseMap)
		{
			it.second->m_material->m_diffuseMap->ApplyTexture(0);
			it.second->m_material->m_shader->SetUniform1f("textureSampler", 0);
		}
		renderer->DrawMesh(it.second);
	}
}

void GameObject::SetMeshMaterial(std::string mesh, Material * mat)
{
	m_meshes[mesh]->SetMaterial(mat);
}

void GameObject::SetGlobalMaterial(Material * mat)
{
	for (auto const& i : m_meshes)
	{
		i.second->SetMaterial(mat);
	}
}

int GameObject::GetMeshCount()
{
	return m_meshes.size();
}

void GameObject::Rotate()
{
	m_modelMatrix = glm::rotate(m_modelMatrix, glm::radians(1.f), glm::vec3(0, 1, 0));
}
