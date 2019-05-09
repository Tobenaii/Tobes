#pragma once
#include "Tobes/Core.h"
#include <string>
#include "Tobes/Common/Component.h"
#include "Tobes/Renderer3D/Vertex.h"
#include <vector>

namespace Tobes
{
	class Model : public Component
	{
	public:
		TOBES_API bool LoadModel(std::string path);
		TOBES_API void SetGlobalMaterial(Material* mat);
		TOBES_API void SetMeshMaterial(int mesh, Material* mat);
		TOBES_API int GetMeshCount();
		TOBES_API Mesh* GetMesh(int index);
		TOBES_API void CreateMesh(Vertex* vertices, unsigned int vertexCount, unsigned int* indices, unsigned int indexCount);

	private:
		~Model();
		TOBES_API virtual void Draw(Renderer* renderer, Camera* camera);
		std::vector<Mesh*> m_meshes;
	};
}
