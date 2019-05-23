#include "Renderer.h"
#include <glew.h>
#include <GLFW/glfw3.h>
#include "Tobes/Renderer3D/Mesh.h"
#include "Tobes/Common/Scene.h"
#include "Tobes/Renderer/Material.h"
#include "Tobes/Renderer3D/Components/MeshRenderer.h"
#include "Tobes/Renderer/Shader.h"
#include <iostream>

namespace Tobes
{
	Renderer::Renderer(GLFWwindow * window)
		:m_window(window)
	{
	}

	void Renderer::Initialize()
	{
		glewInit();
		int width, height;
		glfwGetFramebufferSize(m_window, &width, &height);
		glViewport(0, 0, width, height);
		Material::LoadDefaultShaders();
		Scene::MAX_LIGHTS = 2;
	}

	void Renderer::DrawMesh(Mesh * mesh)
	{
		//Bind current mesh vao and ibo
		glBindVertexArray(mesh->m_vao);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->m_ibo);
		//Draw the mesh triangles
		glDrawElements(GL_TRIANGLES, mesh->m_indexCount, GL_UNSIGNED_INT, nullptr);
	}
	void Renderer::DrawInstancedMesh(Instance* instance)
	{
		glBindVertexArray(instance->mesh->m_vao);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, instance->mesh->m_ibo);
		glDrawElementsInstanced(GL_TRIANGLES, instance->mesh->m_indexCount, GL_UNSIGNED_INT, nullptr, instance->instances);
	}
	void Renderer::DrawSkybox(Mesh* mesh)
	{
		glDepthMask(GL_FALSE);
		DrawMesh(mesh);
		glDepthMask(GL_TRUE);
	}
}
