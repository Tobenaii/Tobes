#include "Camera.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include "Tobes/Common/Components/Transform.h"

namespace Tobes
{
	void Camera::SetPerspective(float fieldOfView, float aspectRatio, float nearPlaneDistance, float farPlaneDistance)
	{
		m_projectionMatrix = Matrix::Perspective(fieldOfView, aspectRatio, nearPlaneDistance, farPlaneDistance);
	}

	void Camera::SetOrthographic(float width, float height, float zNearPlane, float zFarPlane)
	{
		m_projectionMatrix = Matrix::Orthographic(width, height, zNearPlane, zFarPlane);
	}

	Matrix Camera::GetViewProjection()
	{
		m_viewMatrix = Matrix::LookAt(transform->GetPosition(), transform->GetPosition() + transform->GetForward(), transform->GetUp());
		return m_viewMatrix * m_projectionMatrix;
	}
	void Camera::Start()
	{
		//Set default values
		transform->Translate(Vector3(0, 0, -10));
		m_viewMatrix = Matrix::LookAt(transform->GetPosition(), transform->GetPosition() + transform->GetForward(), transform->GetUp());
		SetPerspective(1.f, 1.0f, 0.1f, 1000000.0f);
	}
}


