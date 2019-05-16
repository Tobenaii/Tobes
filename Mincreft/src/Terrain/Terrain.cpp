#include "Terrain.h"
#include "Chunk.h"
#include "Tobes/Renderer3D/Vertex.h"
#include "Tobes/Renderer3D/Mesh.h"
#include "Tobes/Renderer/Material.h"
#include "Tobes/Renderer/Texture.h"

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
	verts = new Vertex[24];

	//bot
	verts[0].position = Vector4(-0.5f, -0.5f, -0.5f, 1);
	verts[1].position = Vector4(0.5f, -0.5f, -0.5f, 1);
	verts[2].position = Vector4(-0.5f, -0.5f, 0.5f, 1);
	verts[3].position = Vector4(0.5f, -0.5f, 0.5f, 1);

	//top
	verts[4].position = Vector4(-0.5f, 0.5f, -0.5f, 1);
	verts[5].position = Vector4(0.5f, 0.5f, -0.5f, 1);
	verts[6].position = Vector4(-0.5f, 0.5f, 0.5f, 1);
	verts[7].position = Vector4(0.5f, 0.5f, 0.5f, 1);

	//left
	verts[8].position = Vector4(-0.5f, -0.5f, 0.5f, 1);
	verts[9].position = Vector4(-0.5f, -0.5f, -0.5f, 1);
	verts[10].position = Vector4(-0.5f, 0.5f, 0.5f, 1);
	verts[11].position = Vector4(-0.5f, 0.5f, -0.5f, 1);

	//right
	verts[12].position = Vector4(0.5f, -0.5f, -0.5f, 1);
	verts[13].position = Vector4(0.5f, -0.5f, 0.5f, 1);
	verts[14].position = Vector4(0.5f, 0.5f, -0.5f, 1);
	verts[15].position = Vector4(0.5f, 0.5f, 0.5f, 1);

	//back
	verts[16].position = Vector4(-0.5f, -0.5f, -0.5f, 1);
	verts[17].position = Vector4(0.5f, -0.5f, -0.5f, 1);
	verts[18].position = Vector4(-0.5f, 0.5f, -0.5f, 1);
	verts[19].position = Vector4(0.5f, 0.5f, -0.5f, 1);

	//front
	verts[20].position = Vector4(-0.5f, -0.5f, 0.5f, 1);
	verts[21].position = Vector4(0.5f, -0.5f, 0.5f, 1);
	verts[22].position = Vector4(-0.5f, 0.5f, 0.5f, 1);
	verts[23].position = Vector4(0.5f, 0.5f, 0.5f, 1);

	unsigned int* indices;
	indices = new unsigned int[36];

	//bot
	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
	indices[3] = 1;
	indices[4] = 2;
	indices[5] = 3;

	//top
	indices[6] = 4;
	indices[7] = 5;
	indices[8] = 6;
	indices[9] = 5;
	indices[10] = 6;
	indices[11] = 7;

	//left
	indices[12] = 8;
	indices[13] = 9;
	indices[14] = 10;
	indices[15] = 9;
	indices[16] = 10;
	indices[17] = 11;

	//right
	indices[18] = 12;
	indices[19] = 13;
	indices[20] = 14;
	indices[21] = 13;
	indices[22] = 14;
	indices[23] = 15;

	//back
	indices[24] = 16;
	indices[25] = 17;
	indices[26] = 18;
	indices[27] = 17;
	indices[28] = 18;
	indices[29] = 19;

	//front
	indices[30] = 20;
	indices[31] = 21;
	indices[32] = 22;
	indices[33] = 21;
	indices[34] = 22;
	indices[35] = 23;

	//bot
	verts[0].textureCoord = Vector2(0, 1);
	verts[1].textureCoord = Vector2(1, 1);
	verts[2].textureCoord = Vector2(0, 0);
	verts[3].textureCoord = Vector2(1, 0);

		//top
		verts[4].textureCoord = Vector2(0, 1);
		verts[5].textureCoord = Vector2(1, 1);
		verts[6].textureCoord = Vector2(0, 0);
		verts[7].textureCoord = Vector2(1, 0);

		//left
		verts[8].textureCoord = Vector2(0, 1);
		verts[9].textureCoord = Vector2(1, 1);
		verts[10].textureCoord = Vector2(0, 0);
		verts[11].textureCoord = Vector2(1, 0);

		//right
		verts[12].textureCoord = Vector2(0, 1);
		verts[13].textureCoord = Vector2(1, 1);
		verts[14].textureCoord = Vector2(0, 0);
		verts[15].textureCoord = Vector2(1, 0);

		//back
		verts[16].textureCoord = Vector2(0, 1);
		verts[17].textureCoord = Vector2(1, 1);
		verts[18].textureCoord = Vector2(0, 0);
		verts[19].textureCoord = Vector2(1, 0);

		//front
		verts[20].textureCoord = Vector2(0, 1);
		verts[21].textureCoord = Vector2(1, 1);
		verts[22].textureCoord = Vector2(0, 0);
		verts[23].textureCoord = Vector2(1, 0);

	m_blockMesh = new Tobes::Mesh(verts, 24, indices, 36);
	m_blockMaterial = new Tobes::Material();
	m_blockMaterial->EnableInstancing();

	Tobes::Texture* texture = new Tobes::Texture("content\\bricks.png");
	m_blockMaterial->SetDiffuseMap(texture);
}
