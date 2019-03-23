#include "Shader.h"
#include <glew.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <glm/common.hpp>
#include <glm/ext.hpp>
#include <iterator>

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

bool Shader::FindKey(std::string key)
{
	std::map<std::string, unsigned int>::iterator it = m_uniformIds.find(key);
	if (it != m_uniformIds.end())
		return true;
	return false;
}

void Shader::AddKey(std::string key)
{
	unsigned int id = glGetUniformLocation(m_programID, key.c_str());
	m_uniformIds[key] = id;
}

void Shader::SetUniformMat4(std::string name, glm::mat4 mat)
{
	if (!FindKey(name))
		AddKey(name);
	glUniformMatrix4fv(m_uniformIds[name], 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::SetUniform1f(std::string name, float value)
{
	if (!FindKey(name))
		AddKey(name);
	glUniform1f(m_uniformIds[name], value);
}

void Shader::SetUniformVec3(std::string name, glm::vec3 vec)
{
	if (!FindKey(name))
		AddKey(name);
	glUniform3f(m_uniformIds[name], vec.x, vec.y, vec.z);
}
