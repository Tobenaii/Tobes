#include "Material.h"

Shader* Material::m_defaultShader = new Shader();

Material::Material()
{

}

void Material::SetDiffuseMap(std::string filePath)
{
	m_diffuseMap = new Texture(filePath);
}

void Material::LoadDiffuseMap(std::string filePath)
{
	Texture* texture = new Texture(filePath);
	m_diffuseMap = texture;
}

void Material::LoadDefaultShaders()
{
	m_defaultShader->LoadVertexShader(".\\content\\shaders\\vertex.txt");
	m_defaultShader->LoadFragmentShader(".\\content\\shaders\\frag.txt");
	m_defaultShader->LinkProgram();
}
