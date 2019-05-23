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
		TOBES_API GameObject(std::string name);
		TOBES_API GameObject(std::string name, GameObject* parent);
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
		TOBES_API std::string GetName();
		void AddChild(GameObject* obj);
		TOBES_API int GetChildCount();
		TOBES_API GameObject* GetChild(int i);

	private:
		GameObject();
		virtual void Draw(Renderer* renderer, Camera* camera);
		virtual void Update(float dt);

		Matrix GetModelMatrix();

		unsigned int m_matrixID;
		unsigned int m_samplerID;
		Scene* m_scene;
		Transform* m_transform;
		std::vector<Component*> m_components;
		std::vector<GameObject*> m_children;
		bool m_isActive = true;
		std::string m_name;
	};
}
