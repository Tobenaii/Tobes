#pragma once
#include <glm/vec4.hpp>

class Light
{
public:
	glm::vec3 m_position;
	glm::vec3 m_direction;
	glm::vec3 m_colour;

	float m_ambientStrength;
};
