#include "Scene.h"
#include "GameObject.h"
#include "Tobes/Renderer3D/Components/Light.h"
#include "Tobes/Renderer/Renderer.h"
#include "Tobes/Renderer/Camera.h"
#include "Tobes/Renderer/Material.h"
#include <algorithm>

namespace Tobes
{
	unsigned int Scene::MAX_LIGHTS = 2;

	Scene::Scene()
	{
	}

	void Scene::AddGameObject(GameObject * object)
	{
		m_gameObjects.push_back(object);
		object->m_scene = this;
	}

	void Scene::RemoveGameObject(GameObject* object)
	{
		delete object;
		m_gameObjects.erase(std::remove(m_gameObjects.begin(), m_gameObjects.end(), object), m_gameObjects.end());
	}

	void Scene::AddLight(Light* light)
	{
		m_lights.push_back(light);
	}

	void Scene::Draw(Renderer * renderer, Camera* camera)
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