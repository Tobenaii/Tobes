#include "Transform.h"

void Tobes::Transform::Start()
{
	m_translationMatrix = Matrix();
	m_rotationMatrix = Matrix();
	m_scaleMatrix = Matrix();
	m_transformMatrix = Matrix();
}

Vector3 Tobes::Transform::GetPosition()
{
	return Vector3(m_translationMatrix.m41, m_translationMatrix.m42, m_translationMatrix.m43);
}

Vector3 Tobes::Transform::GetForward()
{
	return Vector3(m_transformMatrix.m31, m_transformMatrix.m32, m_transformMatrix.m33);
}

Vector3 Tobes::Transform::GetRight()
{
	return Vector3(m_transformMatrix.m11, m_transformMatrix.m12, m_transformMatrix.m13) * -1;
}

Vector3 Tobes::Transform::GetUp()
{
	return Vector3(m_transformMatrix.m21, m_transformMatrix.m22, m_transformMatrix.m23);
}

void Tobes::Transform::Translate(const Vector3 & pos)
{
	m_translationMatrix = m_translationMatrix * Matrix::CreateTranslation(pos);
	m_transformMatrix = m_scaleMatrix * m_rotationMatrix * m_translationMatrix;
}

void Tobes::Transform::Rotate(const Vector3 & axis, const float angle)
{
	Matrix rotation = Matrix::CreateFromAxisAngle(axis, angle);
	m_rotationMatrix = m_rotationMatrix * rotation;
	m_transformMatrix = m_scaleMatrix * m_rotationMatrix * m_translationMatrix;
}

void Tobes::Transform::SetPosition(const Vector3 & pos)
{
	m_translationMatrix = Matrix::CreateTranslation(pos);
}
