#include "Terrain.h"
#include "Chunk.h"

void Terrain::Generate(int chunkWidth, int chunkHeight, int chunkDepth, int chunksX, int chunksY)
{
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
			chunk->Generate(chunkWidth, chunkHeight, chunkDepth);
		}
	}
	chunks = tempChunks;
	this->chunksX = chunksX;
	this->chunksZ = chunksY;
}
