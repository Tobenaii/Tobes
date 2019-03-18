#pragma once
#include "Tobes/Core.h"

struct GLFWwindow;
struct VertexData;
class Mesh;

class TOBES_API Renderer
{
private:
	GLFWwindow* m_window;

public:
	Renderer(GLFWwindow* window);
	void Initialize();
	void DrawTriangle();
	void DrawMesh(Mesh* mesh);
};
