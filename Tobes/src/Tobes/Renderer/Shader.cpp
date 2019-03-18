#include "Shader.h"
#include <glew.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

void Shader::LoadVertexShader(const std::string& filePath)
{
	CreateProgram();
	m_shaderID = glCreateShader(GL_VERTEX_SHADER);
	char const* source = GetShaderSource(filePath);
	CompileShader(source);
}

void Shader::LoadFragmentShader(const std::string & filePath)
{
	CreateProgram();
	m_shaderID = glCreateShader(GL_FRAGMENT_SHADER);
	char const* source = GetShaderSource(filePath);
	CompileShader(source);
}

void Shader::ApplyShader()
{
	glUseProgram(m_programID);
}

unsigned int Shader::GetProgramID()
{
	return m_programID;
}

char const* Shader::GetShaderSource(const std::string & filePath)
{
	std::ifstream fileStream(filePath, std::ios::in);
	if (fileStream.is_open())
	{
		std::stringstream stream;
		stream << fileStream.rdbuf();
		m_source = stream.str();
		fileStream.close();
	}
	else
	{
		std::cout << "Can't open file" << std::endl;
	}
	return m_source.c_str();
}

void Shader::CompileShader(char const* source)
{
	GLint result = GL_FALSE;
	int logLength;

	glShaderSource(m_shaderID, 1, &source, NULL);
	glCompileShader(m_shaderID);

	
	glGetShaderiv(m_shaderID, GL_COMPILE_STATUS, &result);
	glGetShaderiv(m_shaderID, GL_INFO_LOG_LENGTH, &logLength);
	if (!result || logLength > 0)
	{
		std::cout << "Error compiling shader" << std::endl;
		std::vector<char> errorMessage(logLength + 1);
		glGetShaderInfoLog(m_shaderID, logLength, NULL, &errorMessage[0]);
		std::cout << &errorMessage[0] << std::endl;
	}
	else
	{
		AttachShader();
	}
	m_source.clear();
}

void Shader::CreateProgram()
{
	if (m_programID == -1)
		m_programID = glCreateProgram();
}

void Shader::AttachShader()
{
	glAttachShader(m_programID, m_shaderID);
}

void Shader::LinkProgram()
{
	GLint result = GL_FALSE;
	int logLength;
	
	glLinkProgram(m_programID);

	glGetProgramiv(m_programID, GL_LINK_STATUS, &result);
	glGetProgramiv(m_programID, GL_INFO_LOG_LENGTH, &logLength);

	if (!result || logLength > 0)
	{
		std::cout << "Error linking program" << std::endl;
		//TODO: Do some error checking for program not linking
	}

	glDetachShader(m_programID, m_shaderID);
	glDeleteShader(m_shaderID);
}
