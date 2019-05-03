#include "Renderer.h"
#include <glew.h>
#include <GLFW/glfw3.h>
#include "Mesh.h"
#include "Scene.h"
#include "Math/Vector3.h"

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
}
