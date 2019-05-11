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

	void Material::LoadShader(std::string filePath)
	{
		
	}

	void Material::EnableInstancing()
	{
		m_instancing = true;
	}

	void Material::AddMeshInstance(Mesh* mesh)
	{
		if (!m_instance.mesh)
			m_instance.mesh = mesh;
		if (m_instance.mesh == mesh)
			m_instance.instances++;
	}

	void Material::LoadDefaultShaders()
	{
		m_defaultShader->LoadVertexShader(".\\content\\shaders\\vertex.txt");
		m_defaultShader->LoadFragmentShader(".\\content\\shaders\\frag.txt");
		m_defaultShader->LinkProgram();
	}
	Material::~Material()
	{
		delete m_diffuseMap;
	}
}
