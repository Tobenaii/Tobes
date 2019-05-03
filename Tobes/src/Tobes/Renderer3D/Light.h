#pragma once
#include "Tobes/Common/Math/Vector3.h"


class TOBES_API Light
{
public:
	Vector3 position;
	Vector3 direction;
	Vector3 colour;
	float ambientStrength;
};
