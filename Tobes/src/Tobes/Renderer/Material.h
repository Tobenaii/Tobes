#pragma once
#include "Core.h"
#include <string>
#include "Shader.h"
#include "Texture.h"

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

		Texture* m_diffuseMap;
	};
}
