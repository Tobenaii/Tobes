#pragma once
#include "Tobes/Common/Math/Vector3.h"
#include "Tobes/Common/Math/Matrix.h"
#include "Tobes/Common/GameObject.h"

class Camera : public GameObject
{
private:
	Matrix m_projectionMatrix;
	Matrix m_viewMatrix;
	float m_fov;
	float m_aspectRatio;
	float m_near;
	float m_far;

public:
	Camera();
	void SetPerspective(float fieldOfView, float aspectRatio, float nearPlaneDistance, float farPlaneDistance);
	void SetOrthographic(float width, float height, float zNearPlane, float zFarPlane);
	Matrix GetViewProjection();
};