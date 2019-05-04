#pragma once
#include <string>
#include "Tobes/Core.h"

namespace Tobes
{
	class Texture
	{
		friend class Renderer;
		friend class GameObject;
		friend class Model;
		friend class Material;
	public:
		TOBES_API Texture(std::string filePath);
		TOBES_API unsigned int GetTextureID();

	private:
		Texture();
		void ApplyTexture(unsigned int slot);
		~Texture();

		int m_width;
		int m_height;
		int m_bpp;
		unsigned char* m_data;
		unsigned int m_textureID;

		void GenerateTexture();
	};
}
