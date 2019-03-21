#include "Material.h"

Material::Material()
{
	m_shader = new Shader();
	m_shader->LoadVertexShader("D:\\Dev\\Projects\\Tobes\\Tobes\\TestGame\\content\\shaders\\vertex.txt");
	m_shader->LoadFragmentShader("D:\\Dev\\Projects\\Tobes\\Tobes\\TestGame\\content\\shaders\\frag.txt");
	m_shader->LinkProgram();
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
