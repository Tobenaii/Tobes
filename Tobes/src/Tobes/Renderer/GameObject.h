#pragma once
#include "Mesh.h"
#include "Renderer.h"
#include <glm/mat4x4.hpp>
#include "Shader.h"
#include "Camera.h"
#include "Texture.h"
#include <map>

class TOBES_API GameObject
{
public:
	GameObject();
	GameObject(glm::vec3 position);
	glm::mat4 GetModelMatrix();
	void LoadModel(std::string path);
	void Draw(Renderer* renderer, Camera* camera);
	void SetMeshMaterial(std::string mesh, Material* mat);
	void SetGlobalMaterial(Material* mat);
	int GetMeshCount();
	void Rotate();

private:
	glm::mat4 m_translationMatrix;
	glm::mat4 m_scaleMatrix;
	glm::mat4 m_rotationMatrix;
	glm::mat4 m_modelMatrix;
	unsigned int m_matrixID;
	unsigned int m_samplerID;
	
	std::map<std::string, Mesh*> m_meshes;
};
