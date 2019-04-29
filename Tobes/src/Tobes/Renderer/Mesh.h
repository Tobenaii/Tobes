#pragma once
#include <vector>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include "Material.h"

struct Vertex
{
	Vertex()
	{
		position = glm::vec4(0, 0, 0, 1);
		textureCoord = glm::vec2(0, 0);
		normal = glm::vec3(0, 0, 0);
	}
	Vertex(glm::vec4 pos, glm::vec2 texCoord, glm::vec3 norm)
	{
		position = pos;
		textureCoord = texCoord;
		normal = norm;
	}
	glm::vec4 position;
	glm::vec2 textureCoord;
	glm::vec3 normal;
};

class GameObject;

class Mesh
{
	friend class Renderer;
	friend class GameObject;
public:
	Mesh(Vertex* vertices, unsigned int vertexCount, unsigned int* indices, unsigned int indexCount);
	Mesh(GameObject* gameObject);

	const Vertex* GetVertexData();
	void SetData();

private:
	void SetMaterial(Material* mat);

private:
	Vertex* m_vertexData;
	unsigned int* m_indices;

	unsigned int m_vertexCount;
	unsigned int m_indexCount;

	unsigned int m_vbo;
	unsigned int m_ibo;
	unsigned int m_vao;

	Material* m_material;

	GameObject* m_gameObject;
};
