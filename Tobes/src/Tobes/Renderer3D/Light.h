#pragma once
#include "Tobes/Common/Math/Vector3.h"

class Light
{
public:
	Vector3 m_position;
	Vector3 m_direction;
	Vector3 m_colour;

	float m_ambientStrength;
};
