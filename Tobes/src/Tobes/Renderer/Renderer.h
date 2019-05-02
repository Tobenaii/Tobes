#pragma once

struct GLFWwindow;
struct VertexData;
struct Vector3;
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
	void DrawLine(Vector3 start, Vector3 end);
};
