#pragma once
#include <vector>
#include "GameObject.h"
#include "Tobes/Renderer/Light.h"
#include "Tobes/Renderer/Renderer.h"

class TOBES_API Scene
{
	friend class GameObject;
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
