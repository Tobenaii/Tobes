#include "Mesh.h"
#include <glew.h>
#include <fstream>
#include <string>
#include <iostream>
#include <chrono>

namespace Tobes
{
	Mesh::Mesh(Vertex* vertices, unsigned int vertexCount, unsigned int* indices, unsigned int indexCount)
	{
		m_vertexData = vertices;
		m_vertexCount = vertexCount;
		m_indices = indices;
		m_indexCount = indexCount;
		m_name = "";
		SetData();
	}

	Mesh::Mesh(Primitive primitive)
	{
		if (primitive == Skybox)
		{
			CreateSkybox();
		}
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

	void Mesh::SetInstanceData(const Instance& instance)
	{
		glBindVertexArray(m_vao);
		glGenBuffers(1, &m_vboInstance);
		glBindBuffer(GL_ARRAY_BUFFER, m_vboInstance);
		glBufferData(GL_ARRAY_BUFFER, sizeof(Vector3) * instance.instances, &m_offsets[0], GL_STATIC_DRAW);
		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vector3), (void*)0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glVertexAttribDivisor(3, 1);
		glBindVertexArray(0);
	}

	void Mesh::UpdateInstanceData(const Instance& instance)
	{
		if (m_vboInstance == 0)
		{
			SetInstanceData(instance);
			return;
		}
		glBindBuffer(GL_ARRAY_BUFFER, m_vboInstance);
		glBufferData(GL_ARRAY_BUFFER, sizeof(Vector3) * instance.instances, &m_offsets[0], GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

	}

	void Mesh::CreateSkybox()
	{
		Vertex* verts;
		verts = new Vertex[24];

		//bot
		verts[0].position = Vector4(-0.5f, -0.5f, -0.5f, 1);
		verts[1].position = Vector4(0.5f, -0.5f, -0.5f, 1);
		verts[2].position = Vector4(-0.5f, -0.5f, 0.5f, 1);
		verts[3].position = Vector4(0.5f, -0.5f, 0.5f, 1);

		//top
		verts[4].position = Vector4(-0.5f, 0.5f, -0.5f, 1);
		verts[5].position = Vector4(0.5f, 0.5f, -0.5f, 1);
		verts[6].position = Vector4(-0.5f, 0.5f, 0.5f, 1);
		verts[7].position = Vector4(0.5f, 0.5f, 0.5f, 1);

		//left
		verts[8].position = Vector4(-0.5f, -0.5f, 0.5f, 1);
		verts[9].position = Vector4(-0.5f, -0.5f, -0.5f, 1);
		verts[10].position = Vector4(-0.5f, 0.5f, 0.5f, 1);
		verts[11].position = Vector4(-0.5f, 0.5f, -0.5f, 1);

		//right
		verts[12].position = Vector4(0.5f, -0.5f, -0.5f, 1);
		verts[13].position = Vector4(0.5f, -0.5f, 0.5f, 1);
		verts[14].position = Vector4(0.5f, 0.5f, -0.5f, 1);
		verts[15].position = Vector4(0.5f, 0.5f, 0.5f, 1);

		//back
		verts[16].position = Vector4(-0.5f, -0.5f, -0.5f, 1);
		verts[17].position = Vector4(0.5f, -0.5f, -0.5f, 1);
		verts[18].position = Vector4(-0.5f, 0.5f, -0.5f, 1);
		verts[19].position = Vector4(0.5f, 0.5f, -0.5f, 1);

		//front
		verts[20].position = Vector4(-0.5f, -0.5f, 0.5f, 1);
		verts[21].position = Vector4(0.5f, -0.5f, 0.5f, 1);
		verts[22].position = Vector4(-0.5f, 0.5f, 0.5f, 1);
		verts[23].position = Vector4(0.5f, 0.5f, 0.5f, 1);

		unsigned int* indices;
		indices = new unsigned int[36];

		//bot
		indices[0] = 0;
		indices[1] = 1;
		indices[2] = 2;
		indices[3] = 1;
		indices[4] = 2;
		indices[5] = 3;

		//top
		indices[6] = 4;
		indices[7] = 5;
		indices[8] = 6;
		indices[9] = 5;
		indices[10] = 6;
		indices[11] = 7;

		//left
		indices[12] = 8;
		indices[13] = 9;
		indices[14] = 10;
		indices[15] = 9;
		indices[16] = 10;
		indices[17] = 11;

		//right
		indices[18] = 12;
		indices[19] = 13;
		indices[20] = 14;
		indices[21] = 13;
		indices[22] = 14;
		indices[23] = 15;

		//back
		indices[24] = 16;
		indices[25] = 17;
		indices[26] = 18;
		indices[27] = 17;
		indices[28] = 18;
		indices[29] = 19;

		//front
		indices[30] = 20;
		indices[31] = 21;
		indices[32] = 22;
		indices[33] = 21;
		indices[34] = 22;
		indices[35] = 23;

		m_vertexCount = 24;
		m_vertexData = verts;
		m_indexCount = 36;
		m_indices = indices;
		SetData();
	}

	std::string Mesh::GetName()
	{
		return m_name;
	}
}
