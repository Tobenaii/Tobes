#include "Model.h"
#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include "Tobes/Common/Scene.h"
#include "Tobes/Renderer/Camera.h"

void Model::LoadModel(std::string path)
{
	//Start the clock to see how long the load took
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	std::ifstream buffer(path, std::ios::in | std::ios::binary);

	unsigned int meshCount;
	std::string line;
	if (buffer.is_open())
	{
		std::getline(buffer, line);
		meshCount = stoi(line);
		//Go through each mesh
		for (unsigned int m = 0; m < meshCount; m++)
		{
			//Prepare to get the vertex data
			unsigned int vertexCount;
			Vertex* vertexData;
			std::string meshName;
			std::getline(buffer, line);
			meshName = line;
			std::getline(buffer, line);
			vertexCount = stoi(line);
			vertexData = new Vertex[vertexCount];
			//Get vertex data
			for (unsigned int i = 0; i < vertexCount; i++)
			{
				//Get position
				Vector4 pos;
				std::getline(buffer, line);
				pos.x = stof(line);
				std::getline(buffer, line);
				pos.y = stof(line);
				std::getline(buffer, line);
				pos.z = stof(line);
				pos.w = 1.0f;
				//Get texture coodrinate
				Vector2 texCoord;
				std::getline(buffer, line);
				if (stof(line) != -1)
				{
					texCoord.x = stof(line);
					std::getline(buffer, line);
					texCoord.y = stof(line);
				}
				else
					texCoord = Vector2(0, 0);
				//Get normals
				Vector3 norm;
				std::getline(buffer, line);
				norm.x = stof(line);
				std::getline(buffer, line);
				norm.y = stof(line);
				std::getline(buffer, line);
				norm.z = stof(line);
				//Store vertex data in array
				vertexData[i].position = pos;
				vertexData[i].textureCoord = texCoord;
				vertexData[i].normal = norm;
			}
			//Prepare to get indices
			std::getline(buffer, line);
			unsigned int indexCount;
			unsigned int* indices;
			indexCount = stoi(line);
			indices = new unsigned int[indexCount];
			//Get indices
			for (unsigned int i = 0; i < indexCount; i++)
			{
				std::getline(buffer, line);
				indices[i] = stoi(line);
			}
			//Create new mesh and set the mesh data
			Mesh* mesh = new Mesh(vertexData, vertexCount, indices, indexCount);
			m_meshes.push_back(mesh);
			mesh->SetData();
		}
	}
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	std::cout << duration << std::endl;
}

void Model::SetGlobalMaterial(Material * mat)
{
	//Set material for every mesh
	for (auto const& i : m_meshes)
	{
		i->SetMaterial(mat);
	}
}

int Model::GetMeshCount()
{
	return (int)m_meshes.size();
}

void Model::Draw(Renderer * renderer, Camera* camera)
{
	for (const auto& it : m_meshes)
	{
		//TODO: Make functions in material to set uniforms
		if (it->m_material->m_defaultShader)
		{
			it->m_material->m_defaultShader->ApplyShader();
			Matrix mvp = m_modelMatrix * camera->GetViewProjection();
			it->m_material->m_defaultShader->SetUniformMat4("mvp", mvp);
		}
		if (it->m_material->m_diffuseMap)
		{
			it->m_material->m_diffuseMap->ApplyTexture(0);
			it->m_material->m_defaultShader->SetUniform1f("textureSampler", 0);
		}
		//Add each light parameter to corresponding uniform
		//TODO: This is stupid. Implement deferred lighting later
		for (unsigned int i = 0; i < Scene::MAX_LIGHTS; i++)
		{
			if (i >= m_scene->m_lights.size())
				break;
			it->m_material->m_defaultShader->SetUniform1f("ambientStrength" + std::to_string(i), m_scene->m_lights[i]->m_ambientStrength);
			it->m_material->m_defaultShader->SetUniformVec3("lightColour" + std::to_string(i), m_scene->m_lights[i]->m_colour);
			it->m_material->m_defaultShader->SetUniformVec3("lightPos" + std::to_string(i), m_scene->m_lights[i]->m_position);
			it->m_material->m_defaultShader->SetUniformMat4("modelMatrix", m_modelMatrix);
			it->m_material->m_defaultShader->SetUniformVec3("viewPos", camera->GetPosition());
		}
		renderer->DrawMesh(it);
	}
	GameObject::Draw(renderer, camera);
}