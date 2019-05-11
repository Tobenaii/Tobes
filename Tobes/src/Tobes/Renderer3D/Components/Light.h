#pragma once
#include "Tobes/Common/Math/Vector3.h"
#include "Tobes/Common/Component.h"

namespace Tobes
{
	class Light : public Component
	{
	public:
		TOBES_API virtual void Start();
		Vector3 colour;
		float ambientStrength;
	};
}
