#include "File.h"

Tobes::File::~File()
{
	m_dataBuffer->clear();
	m_dataBuffer->shrink_to_fit();
}
