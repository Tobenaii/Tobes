#include "MeshRenderer.h"
#include "Tobes/Renderer/Material.h"
#include "Tobes/Renderer3D/Mesh.h"
#include "Tobes/Renderer/Shader.h"
#include "Tobes/Renderer/Camera.h" 
#include "Tobes/Common/Scene.h"
#include "Tobes/Renderer/Renderer.h"
#include "Tobes/Renderer/Texture.h"
#include "Tobes/Renderer3D/Components/Light.h"
#include "Tobes/Common/Components/Transform.h"
#include "Tobes/Common/GameObject.h"

void Tobes::MeshRenderer::SetMesh(Mesh * mesh)
{
	m_mesh = mesh;
	if (m_material != nullptr && m_material->m_instancing)
		m_material->m_instance.mesh = m_mesh;
}

void Tobes::MeshRenderer::SetMaterial(Material * mat)
{
	m_material = mat;
	if (m_material->m_instancing && m_mesh != nullptr)
		m_material->m_instance.mesh = m_mesh;
}

void Tobes::MeshRenderer::Update(float dt)
{
	if (m_material->m_instancing)
	{
		m_material->m_instanced = false;
		m_mesh->m_offsets.push_back(gameObject->GetTransform()->GetPosition());
		m_material->m_instance.instances++;
	}
}

void Tobes::MeshRenderer::Draw(Renderer * renderer, Camera * camera)
{
	if (m_material->m_instanced)
		return;
	if (m_material->m_defaultShader)
	{
		Material::m_defaultShader->ApplyShader();
		Matrix mvp = transform->m_transformMatrix * camera->GetViewProjection();
		Material::m_defaultShader->SetUniformMat4("mvp", mvp);
	}
	if (m_material->m_diffuseMap)
	{
		m_material->m_diffuseMap->ApplyTexture(0);
		m_material->m_defaultShader->SetUniform1f("textureSampler", 0);
	}
	//Add each light parameter to corresponding uniform
	for (unsigned int i = 0; i < Scene::MAX_LIGHTS; i++)
	{
		if (i >= m_scene->m_lights.size())
			break;
		m_material->m_defaultShader->SetUniform1f("ambientStrength" + std::to_string(i), m_scene->m_lights[i].ambientStrength);
		m_material->m_defaultShader->SetUniformVec3("lightColour" + std::to_string(i), m_scene->m_lights[i].colour);
		m_material->m_defaultShader->SetUniformVec3("lightPos" + std::to_string(i), m_scene->m_lights[i].transform->GetPosition());
		m_material->m_defaultShader->SetUniformMat4("modelMatrix", transform->m_transformMatrix);
		m_material->m_defaultShader->SetUniformVec3("viewPos", camera->transform->GetPosition());
	}
	if (m_material->m_instancing)
	{
		m_mesh->UpdateInstanceData(m_material->m_instance);
		renderer->DrawInstancedMesh(&m_material->m_instance);
		m_material->m_instance.instances = 0;
		m_mesh->m_offsets.clear();
		m_material->m_instanced = true;
	}
	else
		renderer->DrawMesh(m_mesh);
}

void Tobes::MeshRenderer::OnDisable()
{

}

void Tobes::MeshRenderer::OnEnable()
{

}
