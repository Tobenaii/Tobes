#pragma once
#include "Shader.h"
#include "Texture.h"

class Material
{
	friend class GameObject;
	friend class Renderer;
	friend class Mesh;
	friend class Scene;
	
public:
	Material();
	void SetDiffuseMap(std::string filePath);
	void LoadDiffuseMap(std::string filePath);

private:
	static void LoadDefaultShaders();
	static Shader* m_defaultShader;
	Texture* m_diffuseMap;
};
