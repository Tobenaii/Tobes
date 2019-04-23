#include "Mesh.h"
#include <glew.h>
#include <fstream>
#include <string>
#include <iostream>
#include <chrono>
#include <glm/vec2.hpp>
#include "Material.h"

Mesh::Mesh(Vertex* vertices, unsigned int vertexCount, unsigned int* indices, unsigned int indexCount)
{
	m_vertexData = vertices;
	m_vertexCount = vertexCount;
	m_indices = indices;
	m_indexCount = indexCount;
}

Mesh::Mesh(GameObject * gameObject)
{
	m_gameObject = gameObject;
}

const Vertex* Mesh::GetVertexData()
{
	return m_vertexData;
}

void Mesh::SetData()
{
	//Generate and bind vertex array object
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	//Generate and bind vertex buffer object
	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

	//Give vertex data to vbo
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * m_vertexCount, &m_vertexData->position, GL_STATIC_DRAW);

	//Set vertex attributes (positions, texture coordinates, normals
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, textureCoord));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, normal));

	//Generate and bind index buffer object
	glGenBuffers(1, &m_ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	
	//Give index data to ibo
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * m_indexCount, m_indices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Mesh::SetMaterial(Material * mat)
{
	m_material = mat;
}
