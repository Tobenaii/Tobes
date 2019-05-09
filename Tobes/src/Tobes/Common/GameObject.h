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
			component->m_gameObject = this;
			component->m_transform = m_transform;
			component->Start();
			m_components.push_back(component);
			return component;
		}

	private:
		virtual void Draw(Renderer* renderer, Camera* camera);
		virtual void Update(float dt);
		unsigned int m_matrixID;
		unsigned int m_samplerID;
		Scene* m_scene;

	private:
		Matrix GetModelMatrix();
		Transform* m_transform;
		std::vector<Component*> m_components;
	};
}
