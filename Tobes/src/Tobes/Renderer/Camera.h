#pragma once
#include "Tobes/Common/Math/Vector3.h"
#include "Tobes/Common/Math/Matrix.h"
#include "Tobes/Core.h"
#include "Tobes/Common/Component.h"

namespace Tobes
{
	class Camera : public Component
	{
		friend class MeshRenderer;
		friend class Application;

	public:
		TOBES_API void SetPerspective(float fieldOfView, float aspectRatio, float nearPlaneDistance, float farPlaneDistance);
		TOBES_API void SetOrthographic(float width, float height, float zNearPlane, float zFarPlane);

	private:
		Matrix m_projectionMatrix;
		Matrix m_viewMatrix;
		float m_fov;
		float m_aspectRatio;
		float m_near;
		float m_far;

	private:
		Matrix GetViewProjection();
	public:
		virtual void Start();
	};
}
