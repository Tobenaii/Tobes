#pragma once

namespace Tobes
{
	class Texture
	{
	public:
		Texture(const char* fileName);
		~Texture();
	private:
		unsigned char* m_imgData;
		int width, height, components;
	};
}
