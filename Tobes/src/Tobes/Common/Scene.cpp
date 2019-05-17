#include "Scene.h"
#include "GameObject.h"
#include "Tobes/Renderer3D/Components/Light.h"
#include "Tobes/Renderer/Renderer.h"
#include "Tobes/Renderer/Camera.h"
#include "Tobes/Renderer/Material.h"
#include <algorithm>
#include <chrono>
#include <iostream>

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
}