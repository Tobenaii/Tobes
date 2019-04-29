#pragma once

struct GLFWwindow;
struct VertexData;
class Mesh;

class Renderer
{
private:
	GLFWwindow* m_window;

public:
	Renderer(GLFWwindow* window);
	void Initialize();
	void DrawTriangle();
	void DrawMesh(Mesh* mesh);
};
