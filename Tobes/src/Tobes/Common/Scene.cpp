#include "Scene.h"
#include "GameObject.h"

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
}