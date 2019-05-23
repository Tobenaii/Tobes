#pragma once
#include "Tobes/Core.h"
#include "Tobes/Common/Math/Matrix.h"
#include "Tobes/Common/Component.h"

namespace Tobes
{
	class Transform : public Component
	{
		friend class GameObject;
		friend class MeshRenderer;

	private:
		Matrix m_translationMatrix;
		Matrix m_scaleMatrix;
		Matrix m_rotationMatrix;
		Matrix m_transformMatrix;

		virtual void Start();

	public:
		TOBES_API Vector3 GetPosition();
		TOBES_API Vector3 GetForward();
		TOBES_API Vector3 GetRight();
		TOBES_API Vector3 GetUp();

		TOBES_API void Translate(const Vector3& pos);
		TOBES_API void Rotate(const Vector3& axis, const float angle);
		TOBES_API void Scale(const Vector3& scale);
		TOBES_API void SetPosition(const Vector3& pos);
	};
}