#include "Camera.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

Camera::Camera()
{
	//Set default values
	m_position = Vector3(0, 0, -10);
	m_forward = Vector3(0, 0, 1);
	m_viewMatrix = LookAt(m_position, m_position + m_forward, Vector3(0,1,0));
	m_projectionMatrix = Perspective(1.f, 1.0f, 0.1f, 10000.0f);

}

Camera::Camera(Vector3 pos, Vector3 forward, float aspectRatio, float fov)
{
	m_aspectRatio = aspectRatio;
	m_fov = fov;
	m_viewMatrix = LookAt(pos, pos + forward, Vector3(0, 1, 0));
	//TODO: Fix this
	m_projectionMatrix = Perspective(3.14159, m_aspectRatio, 0.1f, 10000.0f);
}

Vector3 Camera::GetPosition()
{
	return m_position;
}

void Camera::SetPosition(Vector3 pos)
{
	m_position = pos;
	m_viewMatrix = LookAt(m_position, m_position + m_forward, { 0.0f,1.0f,0.0f });
}

void Camera::SetForward(Vector3 forward)
{
	m_forward = forward;
	m_viewMatrix = LookAt(m_position, m_position + m_forward, { 0.0f,1.0f,0.0f });
}

void Camera::SetAspectRatio(float aspectRatio)
{
	m_aspectRatio = aspectRatio;
	//m_projectionMatrix = glm::perspective<float>(glm::pi<float>() * m_fov, m_aspectRatio, 0.1f, 1000.0f);
}

void Camera::SetFov(float fov)
{
	m_fov = fov;
	//m_projectionMatrix = glm::perspective<float>(glm::pi<float>() * m_fov, m_aspectRatio, 0.1f, 1000.0f);
}

Matrix Camera::GetProjection()
{
	return m_projectionMatrix;
}

Matrix Camera::GetView()
{
	return m_viewMatrix;
}

Matrix Camera::GetProjectionView()
{
	return m_projectionMatrix * m_viewMatrix;
}

Vector3 Camera::GetForward()
{
	return m_forward;
}

Vector3 Camera::GetRight()
{
	return Cross(m_forward, Vector3(0, 1, 0));
}

Vector3 Camera::GetLocalUp()
{
	return Cross(GetForward(), GetRight());
}
