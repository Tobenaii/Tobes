#include "GameObject.h"
#include <glm/common.hpp>
#include <glm/ext.hpp>
#include <glew.h>

GameObject::GameObject()
{
	m_translationMatrix = glm::mat4(1.0f);
	m_scaleMatrix = glm::mat4(1.0f);
	m_rotationMatrix = glm::mat4(1.0f);
	m_modelMatrix = m_translationMatrix * m_rotationMatrix * m_scaleMatrix;
}

GameObject::GameObject(glm::vec3 position)
{
	m_translationMatrix = glm::translate(glm::mat4(1.0f), position);
	m_scaleMatrix = glm::mat4(1.0f);
	m_rotationMatrix = glm::mat4(1.0f);
	m_modelMatrix = m_translationMatrix * m_rotationMatrix * m_scaleMatrix;
}

glm::mat4 GameObject::GetModelMatrix()
{
	return m_modelMatrix;
}

void GameObject::SetMesh(Mesh * mesh)
{
	m_mesh = mesh;
}

void GameObject::SetShader(Shader * shader)
{
	m_shader = shader;
	m_matrixID = glGetUniformLocation(m_shader->GetProgramID(), "MVP");
}

void GameObject::Draw(Renderer * renderer, Camera* camera)
{
	if (m_shader)
	{
		m_shader->ApplyShader();
		glm::mat4 mvp = camera->GetProjection() * camera->GetView() * m_modelMatrix;
		glUniformMatrix4fv(m_matrixID, 1, GL_FALSE, glm::value_ptr(mvp));
	}
	if (m_mesh->m_children.size() == 0)
		renderer->DrawMesh(m_mesh);
	else
	{
		for (Mesh* mesh : m_mesh->m_children)
			renderer->DrawMesh(mesh);
	}
}
