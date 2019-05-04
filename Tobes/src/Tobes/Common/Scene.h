#pragma once
#include "Tobes/Core.h"
#include <vector>

namespace Tobes
{
	class Camera;

	class Scene
	{
		friend class Model;
		friend class Renderer;
	public:
		TOBES_API Scene();
		TOBES_API void AddGameObject(GameObject* object);
		TOBES_API void RemoveGameObject(GameObject* object);
		TOBES_API void AddLight(Light* light);
		TOBES_API void Draw(Renderer* renderer, Camera* camera);

	private:

		std::vector<GameObject*> m_gameObjects;
		std::vector<Light*> m_lights;
		unsigned int m_ambientID;
		static unsigned int MAX_LIGHTS;
	};
}
