#pragma once
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include "Tobes/Core.h"

class TOBES_API Camera
{
private:
	glm::mat4 m_projectionMatrix;
	glm::mat4 m_viewMatrix;
	float m_fov;
	float m_aspectRatio;
	float m_near;
	float m_far;

public:
	Camera();
	Camera(glm::vec3 pos, glm::vec3 forward, float aspectRatio, float fov);
	glm::vec3 GetPosition();
	void SetPosition(glm::vec3 pos);
	void SetForward(glm::vec3 forward);
	void SetAspectRatio(float aspectRatio);
	void SetFov(float fov);
	glm::mat4 GetProjection();
	glm::mat4 GetView();
	glm::mat4 GetProjectionView();
	glm::vec3 GetForward();
	glm::vec3 GetRight();
	glm::vec3 GetLocalUp();
	glm::vec3 m_position;
	glm::vec3 m_forward;
};