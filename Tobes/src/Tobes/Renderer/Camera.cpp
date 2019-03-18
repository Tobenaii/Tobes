#include "Camera.h"
#include <glm/ext.hpp>

Camera::Camera()
{
	m_viewMatrix = glm::lookAt(glm::vec3(0,10,30.f), {0,10,0}, {0,1,0});
	m_projectionMatrix = glm::perspective<float>(glm::radians(45.0f), 1, 0.01f, 1000.0f);
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
	return glm::vec3(m_viewMatrix[3][0],
		m_viewMatrix[3][1],
		m_viewMatrix[3][2]);
}

void Camera::SetPosition(glm::vec3 pos)
{
	m_viewMatrix[3][0] = pos.x;
	m_viewMatrix[3][1] = pos.y;
	m_viewMatrix[3][2] = pos.z;
}

void Camera::SetForward(glm::vec3 forward)
{
	glm::vec3 pos(m_viewMatrix[3][0], m_viewMatrix[3][1], m_viewMatrix[3][2]);
	m_viewMatrix[2][0] = pos.x + forward.x;
	m_viewMatrix[2][1] = pos.y + forward.y;
	m_viewMatrix[2][2] = pos.z + forward.z;

	glm::vec3 up(m_viewMatrix[1][0], m_viewMatrix[1][1], m_viewMatrix[1][2]);
	glm::vec3 right = glm::cross(up, forward);
	m_viewMatrix[0][0] = right.x;
	m_viewMatrix[0][1] = right.y;
	m_viewMatrix[0][2] = right.z;
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
