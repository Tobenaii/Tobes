#pragma once
#include "Math/Vector3.h"
#include "Math/Matrix.h"
#include "GameObject.h"

class Camera : public GameObject
{
	friend class Model;
	friend class Application;
private:
	Matrix m_projectionMatrix;
	Matrix m_viewMatrix;
	float m_fov;
	float m_aspectRatio;
	float m_near;
	float m_far;

private:
	Camera();
	void SetPerspective(float fieldOfView, float aspectRatio, float nearPlaneDistance, float farPlaneDistance);
	void SetOrthographic(float width, float height, float zNearPlane, float zFarPlane);
	Matrix GetViewProjection();
};
