#pragma once
#include "Tobes/Common/Math/Vector3.h"
#include "Tobes/Common/Math/Matrix.h"

class Camera
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
	Camera(Vector3 pos, Vector3 forward, float aspectRatio, float fov);
	Vector3 GetPosition();
	void SetPosition(Vector3 pos);
	void SetForward(Vector3 forward);
	void SetAspectRatio(float aspectRatio);
	void SetFov(float fov);
	Matrix GetProjection();
	Matrix GetView();
	Matrix GetProjectionView();
	Vector3 GetForward();
	Vector3 GetRight();
	Vector3 GetLocalUp();
	Vector3 m_position;
	Vector3 m_forward;
};