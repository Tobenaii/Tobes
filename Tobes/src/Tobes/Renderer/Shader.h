#pragma once
#include <string>
#include <glm/mat4x4.hpp>
#include <map>

class Shader
{
	friend class Material;
private:
	unsigned int m_programID = -1;
	unsigned int m_shaderID;
	std::string m_source;

public:
	Shader() {}
	void LoadVertexShader(const std::string& filePath);
	void LoadFragmentShader(const std::string& filePath);
	void ApplyShader();
	unsigned int GetProgramID();
	void LinkProgram();
	void SetUniformMat4(std::string name, glm::mat4 mat);
	void SetUniform1f(std::string name, float value);
	void SetUniformVec3(std::string name, glm::vec3 vec);

private:
	char const* GetShaderSource(const std::string& filePath);
	void CompileShader(char const*);
	void CreateProgram();
	void AttachShader();
	bool FindKey(std::string key);
	void AddKey(std::string key);
	
private:
	std::map<std::string, unsigned int> m_uniformIds;
};
