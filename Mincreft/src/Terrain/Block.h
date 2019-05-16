#pragma once
#include "Tobes/Common/GameObject.h"

class Block
{
public:
	enum BlockType { Air, Brick };

public:
	BlockType m_type;
	Tobes::GameObject* m_gameObject;
	Tobes::MeshRenderer* m_renderer;

public:
	void Init(BlockType type, Tobes::GameObject* gameObject, Tobes::Mesh* mesh, Tobes::Material* mat);
	Block() {}
};