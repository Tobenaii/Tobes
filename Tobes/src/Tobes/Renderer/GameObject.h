#pragma once
#include "Mesh.h"
#include "Renderer.h"
#include <glm/mat4x4.hpp>
#include "Shader.h"
#include "Camera.h"

class TOBES_API GameObject
{
public:
	GameObject();
	GameObject(glm::vec3 position);
	glm::mat4 GetModelMatrix();
	void SetMesh(Mesh* mesh);
	void SetShader(Shader* shader);
	void Draw(Renderer* renderer, Camera* camera);

private:
	glm::mat4 m_translationMatrix;
	glm::mat4 m_scaleMatrix;
	glm::mat4 m_rotationMatrix;
	glm::mat4 m_modelMatrix;
	unsigned int m_matrixID;
	Mesh* m_mesh;
	Shader* m_shader;
};
