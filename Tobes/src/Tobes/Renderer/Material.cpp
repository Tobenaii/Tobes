#include "Material.h"
#include "Shader.h"
#include "Texture.h"
#include "Tobes/Application.h"
#include "Tobes/Common/Scene.h"

namespace Tobes
{
	Shader* Material::m_defaultShader = new Shader();

	Material::Material()
	{
		m_diffuseMap = new Texture();
		m_setInstanceData = false;
	}

	void Material::LoadDiffuseMap(std::string filePath)
	{
		Texture* texture = new Texture(filePath);
		SetDiffuseMap(texture);
	}

	void Material::SetDiffuseMap(Texture * texture)
	{
		m_diffuseMap = texture;
	}

	void Material::EnableInstancing()
	{
		m_instancing = true;
	}

	void Material::LoadShader(Shader* shader)
	{
		m_shader = shader;
	}

	void Material::LoadDefaultShaders()
	{
		m_defaultShader->LoadVertexShader(".\\content\\shaders\\vertex.txt");
		m_defaultShader->LoadFragmentShader(".\\content\\shaders\\frag.txt");
		m_defaultShader->LinkProgram();
	}
}
