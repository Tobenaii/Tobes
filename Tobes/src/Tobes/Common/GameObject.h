#pragma once
#include "Core.h"
#include "Mesh.h"
#include "Renderer.h"
#include "Shader.h"
#include "Math/Matrix.h"
#include <map>

namespace Tobes
{
	class Camera;
	class Scene;
	class GameObject
	{
		friend class Scene;
	public:
		TOBES_API GameObject();
		TOBES_API virtual void Translate(const Vector3& pos);
		TOBES_API virtual void Rotate(const Vector3& axis, const float angle);
		TOBES_API void SetPosition(const Vector3& pos);
		TOBES_API Vector3 GetPosition();
		TOBES_API Vector3 GetForward();
		TOBES_API Vector3 GetRight();
		TOBES_API Vector3 GetUp();

	protected:
		virtual void Draw(Renderer* renderer, Camera* camera);
		Matrix m_translationMatrix;
		Matrix m_scaleMatrix;
		Matrix m_rotationMatrix;
		Matrix m_modelMatrix;
		unsigned int m_matrixID;
		unsigned int m_samplerID;
		Scene* m_scene;

	private:
		Matrix GetModelMatrix();
		Vector3 m_forward;
		Vector3 m_right;
	};
}
