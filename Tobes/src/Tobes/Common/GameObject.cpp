#include "GameObject.h"
#include "Components/Transform.h"
#include "Tobes/Application.h"
#include "Scene.h"

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

	void GameObject::Draw(Renderer * renderer, Camera * camera)
	{
		for (Component* component : m_components)
		{
			component->Draw(renderer, camera);
		}
	}

	void GameObject::Update(float dt)
	{
		for (Component* component : m_components)
		{
			component->Update(dt);
		}
	}
}



