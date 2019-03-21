#include "Scene.h"
#include <glew.h>

Scene::Scene()
{
}

void Scene::AddGameObject(GameObject * object)
{
	m_gameObjects.push_back(object);
}

void Scene::AddLight(Light* light)
{
	m_lights.push_back(light);
}

void Scene::Draw(Renderer * renderer, Camera* camera)
{
	glm::vec4 ambientCol(1,1,1,1);
	for (Light* light : m_lights)
	{
		ambientCol *= light->m_ambientColour;
	}
	for (GameObject* obj : m_gameObjects)
	{
		obj->Draw(renderer, camera);
	}
}
