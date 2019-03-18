#pragma once
#include <vector>

class File
{
	friend class ContentManager;
protected:
	virtual void LoadFile(std::string filePath) = 0;
	virtual std::vector<float>* GetRawBytes() = 0;
	virtual ~File() {}
};
