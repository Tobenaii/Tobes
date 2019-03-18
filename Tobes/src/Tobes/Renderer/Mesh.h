#pragma once
#include <vector>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include "Tobes/Core.h"

struct Vertex
{
	Vertex(glm::vec3 pos, glm::vec4 col)
	{
		position = pos;
	}
	Vertex(glm::vec3 pos)
	{
		position = pos;
	}
	glm::vec3 position;
};

class TOBES_API Mesh
{
	friend class Renderer;
	friend class GameObject;
public:
	Mesh(Vertex* vertices, unsigned int vertexCount, unsigned int* indices, unsigned int indexCount);
	Mesh(std::string filePath);

	const Vertex* GetVertexData();

private:
	std::vector<Mesh*> m_children;
	Vertex* m_vertexData;
	unsigned int m_vertexCount;
	unsigned int m_indexCount;

	unsigned int m_vbo;
	unsigned int m_ibo;
	unsigned int m_vao;
};
