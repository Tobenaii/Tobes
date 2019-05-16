#pragma once
#include "Tobes/Core.h"
#include <vector>
#include <string>

namespace Tobes
{
	struct Instance
	{
		Mesh* mesh;
		int instances;
		bool instanced;
	};

	class Material
	{
		friend class Model;
		friend class Renderer;
		friend class Mesh;
		friend class Scene;
		friend class MeshRenderer;

	public:
		TOBES_API Material();
		TOBES_API void LoadDiffuseMap(std::string filePath);
		TOBES_API void SetDiffuseMap(Texture* texture);
		TOBES_API void LoadShader(std::string filePath);
		TOBES_API void EnableInstancing();

	private:
		static void LoadDefaultShaders();
		static Shader* m_defaultShader;
		bool m_instancing;
		bool m_setInstanceData;
		bool m_instanced;
		~Material();
		Instance m_instance;
		Texture* m_diffuseMap;
	};
}
