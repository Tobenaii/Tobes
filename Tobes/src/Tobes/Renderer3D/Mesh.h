#pragma once
#include <vector>
#include "Tobes/Core.h"
#include "Vertex.h"

namespace Tobes
{
	class Mesh
	{
		friend class Renderer;
		friend class Model;

	public:
		TOBES_API std::string GetName();

	private:
		Mesh(Vertex* vertices, unsigned int vertexCount, unsigned int* indices, unsigned int indexCount);
		const Vertex* GetVertexData();
		void SetData();
		void SetMaterial(Material* mat);
		~Mesh();

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
