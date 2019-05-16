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
		void SetActive(bool active) {  m_newActive = active; }

	protected:
		virtual void Start() {};
		virtual void Update(float dt) {};
		virtual void FixedUpdate(float dt) {};
		virtual void Draw(Renderer* renderer, Camera* camera) {}
		virtual void OnDisable() {};
		virtual void OnEnable() {};

	private:
		Scene* m_scene;
		bool m_isActive = true;
		bool m_newActive= true;
	};
}
