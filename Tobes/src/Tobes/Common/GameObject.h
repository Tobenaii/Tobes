#pragma once
#include "Tobes/Renderer3D/Mesh.h"
#include "Tobes/Renderer/Renderer.h"
#include "Tobes/Renderer/Shader.h"
#include "Tobes/Renderer/Camera.h"
#include "Tobes/Common/Math/Matrix.h"
#include <map>

class Scene;

class GameObject
{
	friend class Scene;
public:
	GameObject();
	GameObject(Vector3 position);
	Matrix GetModelMatrix();
	void LoadModel(std::string path);
	void Draw(Renderer* renderer, Camera* camera);
	void SetMeshMaterial(std::string mesh, Material* mat);
	void SetGlobalMaterial(Material* mat);
	int GetMeshCount();
	void SetPosition(const Vector3& pos);

private:
	Matrix m_translationMatrix;
	Matrix m_scaleMatrix;
	Matrix m_rotationMatrix;
	Matrix m_modelMatrix;
	unsigned int m_matrixID;
	unsigned int m_samplerID;
	Scene* m_scene;
	std::map<std::string, Mesh*> m_meshes;
};
