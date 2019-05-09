#pragma once
#include "Tobes/Common/Math/Vector3.h"
#include "Tobes/Common/Component.h"

namespace Tobes
{
	class TOBES_API Light : public Component
	{
	public:
		virtual void Start();
		Vector3 colour;
		float ambientStrength;
	};
}
