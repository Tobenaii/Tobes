#pragma once
#include "Tobes/Common/GameObject.h"
#include "Tobes/Common/Component.h"

class Chunk;

class Terrain : public Tobes::Component
{
public:
	void Generate(int chunkWidth, int chunkHeight, int chunkDepth, int chunksX, int chunksY);
	void CreateBlockMesh();

private:
	Tobes::GameObject** chunks;
	int chunksX;
	int chunksZ;

	Tobes::Mesh* m_blockMesh;
	Tobes::Material* m_blockMaterial;
};
