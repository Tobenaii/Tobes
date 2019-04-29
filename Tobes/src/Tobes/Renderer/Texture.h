#pragma once
#include <string>

class Texture
{
	friend class Renderer;
	friend class GameObject;
public:
	Texture(std::string filePath);
	void ApplyTexture(unsigned int slot);

private:
	int m_width;
	int m_height;
	int m_bpp;
	unsigned char* m_data;
	unsigned int m_textureID;
};
