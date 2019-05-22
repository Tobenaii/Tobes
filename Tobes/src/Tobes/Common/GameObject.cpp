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
		m_name = "GameObject";
	}

	GameObject::GameObject(std::string name)
	{
		m_scene = Application::GetCurrentScene();
		m_scene->AddGameObject(this);
		m_transform = AddComponent<Transform>();
		m_name = name;
	}

	Matrix GameObject::GetModelMatrix()
	{
		return m_transform->m_transformMatrix;
	}

	Transform* GameObject::GetTransform()
	{
		return m_transform;
	}

	std::string GameObject::GetName()
	{
		return m_name;
	}

	void GameObject::Draw(Renderer* renderer, Camera* camera)
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



