#pragma once
#include <vector>
#include "GameObject.h"
#include "Tobes/Renderer3D/Light.h"
#include "Tobes/Renderer/Renderer.h"

class Scene
{
	friend class Model;
	friend class Renderer;
public:
	Scene();
	void AddGameObject(GameObject* object);
	void AddLight(Light* light);
	void Draw(Renderer* renderer, Camera* camera);

private:
	std::vector<GameObject*> m_gameObjects;
	std::vector<Light*> m_lights;
	unsigned int m_ambientID;
	static unsigned int MAX_LIGHTS;
};
