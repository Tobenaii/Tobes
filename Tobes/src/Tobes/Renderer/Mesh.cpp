#include "Mesh.h"
#include <glew.h>
#include <fstream>
#include <string>
#include <iostream>

Mesh::Mesh(Vertex* vertices, unsigned int vertexCount, unsigned int* indices, unsigned int indexCount)
{
	m_vertexCount = vertexCount;
	m_indexCount = indexCount;

	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * m_vertexCount * 3, &vertices->position , GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
	glGenBuffers(1, &m_ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * m_indexCount, indices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

Mesh::Mesh(std::string filePath)
{
	std::ifstream buffer(filePath, std::ios::in|std::ios::binary);

	float numOfMeshes = 0;

	std::string line;
	if (buffer.is_open())
	{
		std::getline(buffer, line);
		numOfMeshes = stof(line);
		for (int m = 0; m < numOfMeshes; m++)
		{
			std::getline(buffer, line);
			int numOfVerts = stof(line);
			std::vector<Vertex> vertices;
			for (int i = 0; i < numOfVerts; i++)
			{
				glm::vec3 pos;
				std::getline(buffer, line);
				pos.x = stof(line);
				std::getline(buffer, line);
				pos.y = stof(line);
				std::getline(buffer, line);
				pos.z = stof(line);
				Vertex vert(pos);
				vertices.push_back(vert);
			}
			std::getline(buffer, line);
			int numOfIndices = stof(line);
			std::vector<unsigned int> indices;
			for (int i = 0; i < numOfIndices; i++)
			{
				std::getline(buffer, line);
				indices.push_back(stof(line));
			}
			Mesh* mesh = new Mesh(&vertices[0], numOfVerts, &indices[0], numOfIndices);
			m_children.push_back(mesh);
		}
	}
}

const Vertex* Mesh::GetVertexData()
{
	return m_vertexData;
}
