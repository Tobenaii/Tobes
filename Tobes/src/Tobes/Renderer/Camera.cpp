#include "Camera.h"
#include <glm/ext.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/rotate_vector.hpp>

Camera::Camera()
{
	m_position = glm::vec3(0, 0, -10);
	m_forward = glm::vec3(0, 0, 1);
	m_viewMatrix = glm::lookAt(m_position, m_position + m_forward, { 0.0f,1.0f,0.0f });

	m_projectionMatrix = glm::perspective<float>(glm::radians(45.0f), 1.0f, 0.1f, 10000.0f);
	//m_projectionMatrix = glm::ortho(-1.f, 1.f, -1.f, 1.f, 0.1f,10.f);
}

Camera::Camera(glm::vec3 pos, glm::vec3 forward, float aspectRatio, float fov)
{
	m_aspectRatio = aspectRatio;
	m_fov = fov;
	m_viewMatrix = glm::lookAt(pos, pos + forward, glm::vec3(0, 1, 0));
	m_projectionMatrix = glm::perspective<float>(glm::pi<float>() * m_fov, m_aspectRatio, 0.1f, 1000.0f);
}

glm::vec3 Camera::GetPosition()
{
	return m_position;
}

void Camera::SetPosition(glm::vec3 pos)
{
	m_position = pos;
	m_viewMatrix = glm::lookAt(m_position, m_position + m_forward, { 0.0f,1.0f,0.0f });
}

void Camera::SetForward(glm::vec3 forward)
{
	m_forward = forward;
	m_viewMatrix = glm::lookAt(m_position, m_position + m_forward, { 0.0f,1.0f,0.0f });
}

void Camera::SetAspectRatio(float aspectRatio)
{
	m_aspectRatio = aspectRatio;
	m_projectionMatrix = glm::perspective<float>(glm::pi<float>() * m_fov, m_aspectRatio, 0.1f, 1000.0f);
}

void Camera::SetFov(float fov)
{
	m_fov = fov;
	m_projectionMatrix = glm::perspective<float>(glm::pi<float>() * m_fov, m_aspectRatio, 0.1f, 1000.0f);
}

glm::mat4 Camera::GetProjection()
{
	return m_projectionMatrix;
}

glm::mat4 Camera::GetView()
{
	return m_viewMatrix;
}

glm::mat4 Camera::GetProjectionView()
{
	return m_projectionMatrix * m_viewMatrix;
}

glm::vec3 Camera::GetForward()
{
	return m_forward;
}

glm::vec3 Camera::GetRight()
{
	return glm::cross(m_forward, glm::vec3(0, 1, 0));
}

glm::vec3 Camera::GetLocalUp()
{
	return glm::cross(GetForward(), GetRight());
}
