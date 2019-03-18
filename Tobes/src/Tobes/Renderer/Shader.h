#pragma once
#include <string>
#include "Tobes/Core.h"

class TOBES_API Shader
{
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

private:
	char const* GetShaderSource(const std::string& filePath);
	void CompileShader(char const*);
	void CreateProgram();
	void AttachShader();
	
};
