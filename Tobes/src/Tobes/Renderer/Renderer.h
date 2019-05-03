#pragma once
#include "Tobes/Core.h"
#include "Mesh.h"

struct GLFWwindow;

class Renderer
{
	friend class Model;
	friend class Application;
private:
	GLFWwindow* m_window;

private:
	Renderer(GLFWwindow* window);
	void Initialize();
	void DrawMesh(Mesh* mesh);
};
