#include "GameObject.h"
#include "Components/Transform.h"
#include "Tobes/Application.h"
#include "Scene.h"
#include <iostream>

namespace Tobes
{
	GameObject::GameObject()
	{
		m_scene = Application::GetCurrentScene();
		m_scene->AddGameObject(this);
		m_transform = AddComponent<Transform>();
	}

	GameObject::~GameObject()
	{
	}

	Matrix GameObject::GetModelMatrix()
	{
		return m_transform->m_transformMatrix;
	}

	Transform* GameObject::GetTransform()
	{
		return m_transform;
	}

	void GameObject::SetActive(bool active)
	{
		if (active && !m_isActive)
			m_scene->AddGameObject(this);
		else if (!active && m_isActive)
			m_scene->RemoveGameObject(this, false);
		m_isActive = active;
	}

	void GameObject::Draw(Renderer * renderer, Camera * camera)
	{
		for (Component* component : m_components)
		{
			if (component->m_newActive != component->m_isActive)
			{
				if (component->m_newActive)
					component->OnEnable();
				else
					component->OnDisable();
				component->m_isActive = component->m_newActive;
				continue;
			}
			if (component->m_isActive)
				component->Draw(renderer, camera);
		}
	}

	void GameObject::Update(float dt)
	{
		for (Component* component : m_components)
		{
			if (component->m_newActive != component->m_isActive)
			{
				if (component->m_newActive)
					component->OnEnable();
				else
					component->OnDisable();
				component->m_isActive = component->m_newActive;
				continue;
			}
			if (component->m_isActive)
				component->Update(dt);
		}
	}
}



