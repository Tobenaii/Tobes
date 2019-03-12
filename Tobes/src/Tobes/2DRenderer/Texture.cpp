#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace Tobes
{
	Texture::Texture(const char * fileName)
	{
		m_imgData = stbi_load(fileName, &width, &height, &components, 0);
	}

	Texture::~Texture()
	{
		stbi_image_free(m_imgData);
	}
}
