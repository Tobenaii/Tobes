#pragma once
#include "Tobes/Common/Math/Vector3.h"
#include "Tobes/Common/Math/Matrix.h"
#include "Tobes/Core.h"
#include "Tobes/Common/GameObject.h"

namespace Tobes
{
	class Camera : public GameObject
	{
		friend class Model;
		friend class Application;
	private:
		Matrix m_projectionMatrix;
		Matrix m_viewMatrix;
		float m_fov;
		float m_aspectRatio;
		float m_near;
		float m_far;

	private:
		Camera();
		void SetPerspective(float fieldOfView, float aspectRatio, float nearPlaneDistance, float farPlaneDistance);
		void SetOrthographic(float width, float height, float zNearPlane, float zFarPlane);
		Matrix GetViewProjection();
	};
}
