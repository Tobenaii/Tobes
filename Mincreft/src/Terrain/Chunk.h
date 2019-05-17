#pragma once
#include "Tobes/Common/Component.h"
#include "Block.h"
#include "Tobes/Renderer3D/Vertex.h"
#include <vector>

class Scene;

class Chunk : public Tobes::Component
{
friend class Terrain;

private:
	float m_width;
	float m_height;
	float m_depth;

	void Generate(int width, int height, int depth, Tobes::Mesh* mesh, Tobes::Material* mat);
	void RenderCheck(int x, int y, int z);
	Block*** blocks;
};
