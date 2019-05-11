#pragma once
#include "Tobes/Core.h"
#include "Tobes/Common/Math/Matrix.h"
#include "Tobes/Common/Component.h"
#include <vector>
#include <map>

namespace Tobes
{
	class Transform;
	class GameObject
	{
		friend class Scene;
		friend class Application;
	public:
		TOBES_API GameObject();
		TOBES_API ~GameObject();
		template<class T>
		inline T* AddComponent()
		{
			T* component = new T();
			component->m_scene = m_scene;
			component->gameObject = this;
			component->transform = m_transform;
			component->Start();
			m_components.push_back(component);
			return component;
		}
		TOBES_API Transform* GetTransform();

	private:
		virtual void Draw(Renderer* renderer, Camera* camera);
		virtual void Update(float dt);
		Matrix GetModelMatrix();

		unsigned int m_matrixID;
		unsigned int m_samplerID;
		Scene* m_scene;
		Transform* m_transform;
		std::vector<Component*> m_components;
	};
}
