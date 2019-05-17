#pragma once
#include "Tobes/Core.h"
#include <vector>

namespace Tobes
{
	class Camera;

	class Scene
	{
		friend class MeshRenderer;
		friend class Renderer;
		friend class Material;

	public:
		TOBES_API Scene();
		TOBES_API void AddGameObject(GameObject* object);
		TOBES_API void AddLight(Light* light);
		TOBES_API void Draw(Renderer* renderer, Camera* camera);
		TOBES_API void Update(float dt);

	private:
		std::vector<GameObject*> m_gameObjects;
		std::vector<Light*> m_lights;
		unsigned int m_ambientID;
		static unsigned int MAX_LIGHTS;
	};
}
