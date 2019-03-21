#pragma once
#include "Shader.h"
#include "Texture.h"

class TOBES_API Material
{
	friend class GameObject;
	friend class Renderer;
	friend class Mesh;
public:
	Material();
	void SetDiffuseMap(std::string filePath);
	void LoadDiffuseMap(std::string filePath);

private:
	Shader* m_shader;
	Texture* m_diffuseMap;
};
