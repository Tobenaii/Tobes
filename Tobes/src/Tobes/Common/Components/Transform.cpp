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

void Tobes::Transform::Scale(const Vector3 & scale)
{
	m_scaleMatrix.m11 = scale.x;
	m_scaleMatrix.m12 = 0;
	m_scaleMatrix.m13 = 0;
	m_scaleMatrix.m14 = 0;
	m_scaleMatrix.m21 = 0;
	m_scaleMatrix.m22 = scale.y;
	m_scaleMatrix.m23 = 0;
	m_scaleMatrix.m24 = 0;
	m_scaleMatrix.m31 = 0;
	m_scaleMatrix.m32 = 0;
	m_scaleMatrix.m33 = scale.z;
	m_scaleMatrix.m34 = 0;
	m_scaleMatrix.m41 = 0;
	m_scaleMatrix.m42 = 0;
	m_scaleMatrix.m43 = 0;
	m_scaleMatrix.m44 = 1;
	m_transformMatrix = m_scaleMatrix * m_rotationMatrix * m_translationMatrix;
}

void Tobes::Transform::SetPosition(const Vector3 & pos)
{
	m_translationMatrix = Matrix::CreateTranslation(pos);
}
