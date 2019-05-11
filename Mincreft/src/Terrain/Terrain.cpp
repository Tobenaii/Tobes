#include "Terrain.h"
#include "Chunk.h"
#include "Tobes/Renderer3D/Vertex.h"
#include "Tobes/Renderer3D/Mesh.h"
#include "Tobes/Renderer/Material.h"

void Terrain::Generate(int chunkWidth, int chunkHeight, int chunkDepth, int chunksX, int chunksY)
{
	CreateBlockMesh();
	Tobes::GameObject** tempChunks = new Tobes::GameObject*[chunksX];
	for (int y = 0; y < chunksX; y++)
	{
		tempChunks[y] = new Tobes::GameObject[chunksY];
	}
	for (int x = 0; x < chunksX; x++)
	{
		for (int y = 0; y < chunksY; y++)
		{
			Chunk* chunk = tempChunks[x][y].AddComponent<Chunk>();
			chunk->Generate(chunkWidth, chunkHeight, chunkDepth, m_blockMesh, m_blockMaterial);
		}
	}
	chunks = tempChunks;
	this->chunksX = chunksX;
	this->chunksZ = chunksY;
}

void Terrain::CreateBlockMesh()
{
	Vertex* verts;
	verts = new Vertex[8];

	verts[0].position = Vector4(-1, -1, -1, 1);
	verts[1].position = Vector4(1, -1, -1, 1);
	verts[2].position = Vector4(-1, -1, 1, 1);
	verts[3].position = Vector4(1, -1, 1, 1);

	verts[4].position = Vector4(-1, 1, -1, 1);
	verts[5].position = Vector4(1, 1, -1, 1);
	verts[6].position = Vector4(-1, 1, 1, 1);
	verts[7].position = Vector4(1, 1, 1, 1);

	unsigned int* indices;
	indices = new unsigned int[12];

	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;

	indices[3] = 1;
	indices[4] = 2;
	indices[5] = 3;

	indices[6] = 4;
	indices[7] = 5;
	indices[8] = 6;

	indices[9] = 5;
	indices[10] = 6;
	indices[11] = 7;

	m_blockMesh = new Tobes::Mesh(verts, 8, indices, 12);
	m_blockMaterial = new Tobes::Material();
	m_blockMaterial->EnableInstancing();
}
