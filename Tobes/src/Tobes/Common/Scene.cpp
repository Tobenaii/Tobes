#include "Scene.h"
#include "GameObject.h"
#include "Tobes/Renderer3D/Components/Light.h"
#include "Tobes/Renderer/Renderer.h"
#include "Tobes/Renderer/Camera.h"
#include "Tobes/Renderer/Material.h"
#include "Tobes/Content/ContentManager.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include "Tobes/Renderer3D/Mesh.h"
#include "Tobes/Renderer3D/Components/MeshRenderer.h"

namespace Tobes
{
	unsigned int Scene::MAX_LIGHTS = 2;

	Scene::Scene()
	{
	}

	void Scene::AddGameObject(GameObject* object)
	{
		m_gameObjects.push_back(object);
	}

	int Scene::GetGameObjectCount()
	{
		return m_gameObjects.size();
	}

	GameObject * Scene::GetGameObject(int i)
	{
		return m_gameObjects[i];
	}

	void Scene::AddLight(Light* light)
	{
		m_lights.push_back(light);
	}

	void Scene::Draw(Renderer* renderer, Camera* camera)
	{
		for (GameObject* obj : m_gameObjects)
		{
			obj->Draw(renderer, camera);
		}
	}
	void Scene::Update(float dt)
	{
		for (GameObject* obj : m_gameObjects)
		{
			obj->Update(dt);
		}
	}
	GameObject * Scene::LoadModel(std::string filePath)
	{
		std::filesystem::path p = filePath;
		if (p.extension() != ".tbs")
			return nullptr;
		//Start the clock to see how long the load took
		std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
		std::ifstream buffer(filePath, std::ios::in | std::ios::binary);
		bool open = false;
		unsigned int meshCount;
		std::string line;
		if (buffer.is_open())
		{
			open = true;
			std::getline(buffer, line);
			meshCount = stoi(line);
			//Go through each mesh
			try
			{
				for (unsigned int m = 0; m < meshCount; m++)
				{
					//Prepare to get the vertex data
					unsigned int vertexCount;
					Vertex* vertexData;
					std::string meshName;
					std::getline(buffer, line);
					meshName = line;
					if (meshName == "")
						meshName = "Mesh: " + std::to_string(m + 1);
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
					GameObject* go = new GameObject(meshName);
					MeshRenderer* renderer = go->AddComponent<MeshRenderer>();
					renderer->SetMaterial(new Material());
					renderer->SetMesh(mesh);
				}
			}
			catch (...)
			{
				std::cout << "Mesh loading error" << std::endl;
			}
		}
		std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
		std::cout << "Time to load .tbs file: " << duration << std::endl;
		return nullptr;
	}
}