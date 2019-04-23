#include "ImageFile.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <chrono>
#include <iostream>

void ImageFile::LoadFile(std::string filePath)
{
	//NOT IN USE RIGHT NOW

	//Start clock to get load time
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	//load image using stbi
	stbi_set_flip_vertically_on_load(1);
	unsigned char* data = stbi_load(filePath.c_str(), &m_width, &m_height, &m_bpp, 4);
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	std::cout << duration << std::endl;
	//Save bytes to buffer
	m_buffer = std::vector<unsigned char>(data, data + m_width * m_height * m_bpp);
	m_info.push_back(m_width);
	m_info.push_back(m_height);
	m_info.push_back(4);
}

std::vector<unsigned char>* ImageFile::GetImageData()
{
	return &m_buffer;
}

std::vector<unsigned int>* ImageFile::GetInfo()
{
	return &m_info;
}
