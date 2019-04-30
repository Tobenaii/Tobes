#pragma once
#include <vector>
#include "Tobes/Common/Math/Vector2.h"
#include "Tobes/Common/Math/Vector3.h"
#include "Tobes/Common/Math/Vector4.h"
#include "Tobes/Renderer/Material.h"

struct Vertex
{
	Vertex()
	{
		position = Vector4(0, 0, 0, 1);
		textureCoord = Vector2(0, 0);
		normal = Vector3(0, 0, 0);
	}
	Vertex(Vector4 pos, Vector2 texCoord, Vector3 norm)
	{
		position = pos;
		textureCoord = texCoord;
		normal = norm;
	}
	Vector4 position;
	Vector2 textureCoord;
	Vector3 normal;
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
