#include "Block.h"
#include "Tobes/Renderer3D/Components/MeshRenderer.h"

void Block::Init(BlockType type, Tobes::GameObject* gameObject, Tobes::Mesh* mesh, Tobes::Material* mat)
{
	m_type = type;
	m_gameObject = gameObject;

	Tobes::MeshRenderer* renderer = m_gameObject->AddComponent<Tobes::MeshRenderer>();
	renderer->SetMesh(mesh);
	renderer->SetMaterial(mat);
	m_renderer = renderer;
}
