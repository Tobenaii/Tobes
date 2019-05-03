#pragma once
#include <vector>
#include "Tobes/Core.h"
#include "Tobes/Common/Math/Vector2.h"
#include "Tobes/Common/Math/Vector3.h"
#include "Tobes/Common/Math/Vector4.h"
namespace Tobes
{
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

	class Mesh
	{
		friend class Renderer;
		friend class Model;

	private:
		Mesh(Vertex* vertices, unsigned int vertexCount, unsigned int* indices, unsigned int indexCount);
		const Vertex* GetVertexData();
		void SetData();
		std::string GetName();
		void SetMaterial(Material* mat);

	private:
		Vertex* m_vertexData;
		unsigned int* m_indices;

		unsigned int m_vertexCount;
		unsigned int m_indexCount;

		unsigned int m_vbo;
		unsigned int m_ibo;
		unsigned int m_vao;

		std::string m_name;

		Material* m_material;
		GameObject* m_gameObject;
	};
}
