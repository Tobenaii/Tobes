#pragma once
#include "Tobes/Core.h"

namespace Tobes
{
	class Transform;
	class Component
	{
		friend class GameObject;
		friend class MeshRenderer;
		friend class Light;

	public:
		Transform* transform;
		GameObject* gameObject;

	public:
		virtual void Start() {};
		virtual void Update(float dt) {};
		virtual void FixedUpdate(float dt) {};
		virtual void Draw(Renderer* renderer, Camera* camera) {}

	private:
		Scene* m_scene;
	};
}
