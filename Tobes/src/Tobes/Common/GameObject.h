#pragma once
#include "Tobes/Renderer/Mesh.h"
#include "Tobes/Renderer/Renderer.h"
#include "Tobes/Renderer/Shader.h"
#include "Tobes/Renderer/Camera.h"
#include "Tobes/Common/Math.h"
#include <map>

class Scene;

class GameObject
{
	friend class Scene;
public:
	GameObject();
	GameObject(Vector3 position);
	glm::mat4 GetModelMatrix();
	void LoadModel(std::string path);
	void Draw(Renderer* renderer, Camera* camera);
	void SetMeshMaterial(std::string mesh, Material* mat);
	void SetGlobalMaterial(Material* mat);
	int GetMeshCount();
	void SetPosition(const glm::vec3& pos);
	void Rotate(const glm::vec3& axis, const float rot);

private:
	glm::mat4 m_translationMatrix;
	glm::mat4 m_scaleMatrix;
	glm::mat4 m_rotationMatrix;
	glm::mat4 m_modelMatrix;
	unsigned int m_matrixID;
	unsigned int m_samplerID;
	Scene* m_scene;
	std::map<std::string, Mesh*> m_meshes;
};
