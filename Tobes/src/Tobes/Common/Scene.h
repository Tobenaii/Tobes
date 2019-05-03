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
		TOBES_API void AddLight(Light* light);

	private:
		void Draw(Renderer* renderer, Camera* camera);

		std::vector<GameObject*> m_gameObjects;
		std::vector<Light*> m_lights;
		unsigned int m_ambientID;
		static unsigned int MAX_LIGHTS;
	};
}
