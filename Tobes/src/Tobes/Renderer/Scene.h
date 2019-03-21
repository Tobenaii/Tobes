#pragma once
#include <vector>
#include "GameObject.h"
#include "Light.h"
#include "Renderer.h"

class TOBES_API Scene
{
public:
	Scene();
	void AddGameObject(GameObject* object);
	void AddLight(Light* light);
	void Draw(Renderer* renderer, Camera* camera);

private:
	std::vector<GameObject*> m_gameObjects;
	std::vector<Light*> m_lights;
	unsigned int m_ambientID;
};
