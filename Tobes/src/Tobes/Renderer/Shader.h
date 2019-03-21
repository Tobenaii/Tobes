#pragma once
#include <string>
#include "Tobes/Core.h"
#include <glm/mat4x4.hpp>

class TOBES_API Shader
{
	friend class Material;
private:
	unsigned int m_programID = -1;
	unsigned int m_shaderID;
	std::string m_source;

public:
	void LoadVertexShader(const std::string& filePath);
	void LoadFragmentShader(const std::string& filePath);
	void ApplyShader();
	unsigned int GetProgramID();
	void LinkProgram();
	void SetUniformMat4(std::string name, glm::mat4 mat);
	void SetUniform1f(std::string name, float value);

private:
	char const* GetShaderSource(const std::string& filePath);
	void CompileShader(char const*);
	void CreateProgram();
	void AttachShader();
	
private:
	unsigned int m_matrixID = -1;
	unsigned int m_samplerID = -1;
};
