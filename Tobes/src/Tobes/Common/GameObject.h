#pragma once
#include "Tobes/Renderer3D/Mesh.h"
#include "Tobes/Renderer/Renderer.h"
#include "Tobes/Renderer/Shader.h"
#include "Tobes/Common/Math/Matrix.h"
#include <map>

class Scene;
class Camera;

class GameObject
{
	friend class Scene;
public:
	GameObject();
	Matrix GetModelMatrix();
	
	virtual void Draw(Renderer* renderer, Camera* camera);

	virtual void Translate(const Vector3& pos);
	virtual void Rotate(const Vector3& axis, const float angle);

	void SetPosition(const Vector3& pos);

	Vector3 GetPosition();
	Vector3 GetForward();
	Vector3 GetRight();
	Vector3 GetUp();

protected:
	Matrix m_translationMatrix;
	Matrix m_scaleMatrix;
	Matrix m_rotationMatrix;
	Matrix m_modelMatrix;
	unsigned int m_matrixID;
	unsigned int m_samplerID;
	Scene* m_scene;

private:
	Vector3 m_forward;
	Vector3 m_right;
};
