#include "Renderer.h"
#include <glew.h>
#include <GLFW/glfw3.h>
#include "Tobes/Renderer3D/Mesh.h"
#include "Tobes/Common/Scene.h"
#include "Tobes/Common/Math/Vector3.h"

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
	//Bind current mesh vao and ibo
	glBindVertexArray(mesh->m_vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->m_ibo);
	//Draw the mesh triangles
	glDrawElements(GL_TRIANGLES, mesh->m_indexCount, GL_UNSIGNED_INT, nullptr);
}

void Renderer::DrawLine(Vector3 start, Vector3 end)
{
	glLineWidth(2.5f);
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(start.x, start.y, start.z);
	glVertex3d(end.x, end.y, end.z);
	glEnd();
}
