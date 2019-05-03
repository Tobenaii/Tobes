#include <glew.h>
#include "Texture.h"
#include <fstream>
#include <string>
#include <iostream>
#include <chrono>
#include <istream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace Tobes
{
	Texture::Texture(std::string filePath)
	{
		//Load texture using stbi
		stbi_set_flip_vertically_on_load(1);
		m_data = stbi_load(filePath.c_str(), &m_width, &m_height, &m_bpp, 4);

		GenerateTexture();
	}

	Texture::Texture()
	{
		m_data = new unsigned char[4];
		m_data[0] = 255;
		m_data[1] = 255;
		m_data[2] = 255;
		m_data[3] = 255;
		m_width = 1;
		m_height = 1;
		GenerateTexture();
	}

	void Texture::ApplyTexture(unsigned int slot)
	{
		glActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, m_textureID);
	}

	void Texture::GenerateTexture()
	{
		//Generate and bind texture buffer 
		glGenTextures(1, &m_textureID);
		glBindTexture(GL_TEXTURE_2D, m_textureID);
		//Apply settings for how opengl should interpret the texture
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_WRAP_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_WRAP_BORDER);
		//Generate texture and unbind for cleanup
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_data);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}
