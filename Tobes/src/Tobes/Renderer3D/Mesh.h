#pragma once
#include <vector>
#include "Tobes/Core.h"
#include "Vertex.h"
#include "Tobes/Renderer/Material.h"


namespace Tobes
{
	class Mesh
	{
		friend class Renderer;
		friend class MeshRenderer;

	public:
		TOBES_API std::string GetName();
		TOBES_API Mesh(Vertex* vertices, unsigned int vertexCount, unsigned int* indices, unsigned int indexCount);

	private:
		const Vertex* GetVertexData();
		void SetData();
		void SetInstanceData(const Instance& instance);
		void UpdateInstanceData(const Instance& instance);

	private:
		Vertex* m_vertexData;
		unsigned int* m_indices;

		unsigned int m_vertexCount;
		unsigned int m_indexCount;

		unsigned int m_vbo;
		unsigned int m_vboInstance;
		unsigned int m_ibo;
		unsigned int m_vao;

		std::string m_name;
		GameObject* m_gameObject;
		std::vector<Vector3> m_offsets;
	};
}
