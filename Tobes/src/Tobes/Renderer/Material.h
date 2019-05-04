#pragma once
#include "Tobes/Core.h"
#include <string>

namespace Tobes
{
	class Material
	{
		friend class Model;
		friend class Renderer;
		friend class Mesh;
		friend class Scene;

	public:
		TOBES_API Material();
		TOBES_API void LoadDiffuseMap(std::string filePath);

	private:
		static void LoadDefaultShaders();
		static Shader* m_defaultShader;
		~Material();

		Texture* m_diffuseMap;
	};
}
