#include "Renderer.h"
#include <glew.h>
#include <GLFW/glfw3.h>
#include "Mesh.h"
#include "Tobes/Common/Scene.h"

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

void Renderer::DrawTriangle()
{
	//static const float vertexBufferData[] = {
 //  -0.5f, -0.5f, 0.0f,
 //  0.5f, -0.5f, 0.0f,
 //  -0.5f,  0.5f, 0.0f,
 //  0.5f,  0.5f, 0.0f,
	//};
	//DrawMesh();
}

void Renderer::DrawMesh(Mesh* mesh)
{
	glBindVertexArray(mesh->m_vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->m_ibo);
	glDrawElements(GL_TRIANGLES, mesh->m_indexCount, GL_UNSIGNED_INT, nullptr);
}
