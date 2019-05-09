#pragma once
#include "Tobes/Core.h"

namespace Tobes
{
	class Transform;
	class Component
	{
		friend class GameObject;

	protected:
		Transform* m_transform;
		Scene* m_scene;
		GameObject* m_gameObject;
		GameObject* Instantiate(GameObject* gameObject);

	public:
		virtual void Update(float dt) {};
		virtual void FixedUpdate(float dt) {};
		virtual void Draw(Renderer* renderer, Camera* camera) {}
		virtual void Start() {};
		inline Transform* GetTransform() { return m_transform; }
	};
}
