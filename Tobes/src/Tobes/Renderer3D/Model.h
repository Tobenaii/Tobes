#pragma once
#include "Core.h"
#include <string>
#include "Mesh.h"
#include <vector>

namespace Tobes
{
	class Model : public GameObject
	{
	public:
		TOBES_API bool LoadModel(std::string path);
		TOBES_API void SetGlobalMaterial(Material* mat);

	private:
		int GetMeshCount();
		Mesh* GetMesh(int index);
		void Draw(Renderer* renderer, Camera* camera);
		std::vector<Mesh*> m_meshes;
	};
}
