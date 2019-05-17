#pragma once
#include "Tobes/Core.h"
#include "Tobes/Common/Component.h"

namespace Tobes
{
	class MeshRenderer : public Component
	{
	public:
		TOBES_API void SetMesh(Mesh* mesh);
		TOBES_API void SetMaterial(Material* mat);
		TOBES_API virtual void Update(float dt);
		TOBES_API virtual void Draw(Renderer* renderer, Camera* camera);

	private:
		Mesh* m_mesh;
		Material* m_material;
		int m_instanceIndex;
	};
}