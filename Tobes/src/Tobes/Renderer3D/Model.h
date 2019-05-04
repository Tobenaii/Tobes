#pragma once
#include "Tobes/Core.h"
#include <string>
#include "Tobes/Common/GameObject.h" 
#include <vector>

namespace Tobes
{
	class Model : public GameObject
	{
	public:
		TOBES_API bool LoadModel(std::string path);
		TOBES_API void SetGlobalMaterial(Material* mat);
		TOBES_API void SetMeshMaterial(int mesh, Material* mat);
		TOBES_API int GetMeshCount();
		TOBES_API Mesh* GetMesh(int index);

	private:

		TOBES_API ~Model();
		TOBES_API void Draw(Renderer* renderer, Camera* camera);
		std::vector<Mesh*> m_meshes;
	};
}
