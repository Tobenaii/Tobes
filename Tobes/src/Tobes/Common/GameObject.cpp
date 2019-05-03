#include "GameObject.h"
#include "Camera.h"

namespace Tobes
{
	GameObject::GameObject()
	{
		m_translationMatrix = Matrix();
		m_scaleMatrix = Matrix();
		m_rotationMatrix = Matrix();

		m_modelMatrix = m_scaleMatrix * m_rotationMatrix * m_translationMatrix;
	}

	Matrix GameObject::GetModelMatrix()
	{
		return m_modelMatrix;
	}

	void GameObject::Draw(Renderer * renderer, Camera * camera)
	{
		//TODO: Draw debug lines?
	}

	void GameObject::Translate(const Vector3& pos)
	{
		m_translationMatrix = m_translationMatrix * Matrix::CreateTranslation(pos);
		m_modelMatrix = m_scaleMatrix * m_rotationMatrix * m_translationMatrix;
	}

	void GameObject::Rotate(const Vector3 & axis, const float angle)
	{
		Matrix rotation = Matrix::CreateFromAxisAngle(axis, angle);
		m_rotationMatrix = m_rotationMatrix * rotation;
		m_modelMatrix = m_scaleMatrix * m_rotationMatrix * m_translationMatrix;
	}

	void GameObject::SetPosition(const Vector3 & pos)
	{
		m_translationMatrix = Matrix::CreateTranslation(pos);
		m_modelMatrix = m_scaleMatrix * m_rotationMatrix * m_translationMatrix;
	}

	Vector3 GameObject::GetPosition()
	{
		return Vector3(m_translationMatrix.m41, m_translationMatrix.m42, m_translationMatrix.m43);
	}

	Vector3 GameObject::GetForward()
	{
		return Vector3(m_modelMatrix.m31, m_modelMatrix.m32, m_modelMatrix.m33);
	}

	Vector3 GameObject::GetRight()
	{
		return Vector3(m_modelMatrix.m11, m_modelMatrix.m12, m_modelMatrix.m13) * -1;
	}

	Vector3 GameObject::GetUp()
	{
		return Vector3(m_modelMatrix.m21, m_modelMatrix.m22, m_modelMatrix.m23);
	}
}



