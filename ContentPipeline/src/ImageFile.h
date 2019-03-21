#pragma once
#include "File.h"

class ImageFile : public File
{
public:
	virtual void LoadFile(std::string filePath);
	virtual std::vector<unsigned char>* GetImageData();
	virtual std::vector<unsigned int>* GetInfo();

private:
	int m_width;
	int m_height;
	int m_bpp;
	std::vector<unsigned char> m_buffer; 
	std::vector<unsigned int> m_info;
};
