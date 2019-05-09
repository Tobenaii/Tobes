#include "Component.h"
#include "GameObject.h"
#include "Scene.h"

namespace Tobes
{
	GameObject* Tobes::Component::Instantiate(GameObject * gameObject)
	{
		GameObject* newObject(gameObject);
		m_scene->AddGameObject(newObject);
		return newObject;
	}
}
