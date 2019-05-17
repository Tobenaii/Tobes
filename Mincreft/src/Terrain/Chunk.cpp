#include "Chunk.h"
#include <iostream>
#include "Tobes/Common/GameObject.h"
#include "Tobes/Renderer3D/Components/MeshRenderer.h"
#include "Tobes/Common/Components/Transform.h"
#include "Block.h"
#include <iostream>

void Chunk::Generate(int width, int height, int depth, Tobes::Mesh* mesh, Tobes::Material* mat)
{
	m_width = width;
	m_height = height;
	m_depth = depth;

	Block*** tempBlocksY = new Block**[height];
	for (int y = 0; y < height; y++)
	{
		Block** tempBlocksX = new Block*[width];
		for (int x = 0; x < width; x++)
		{
			Block* tempBlocksZ = new Block[depth];
			for (int z = 0; z < depth; z++)
			{
				Tobes::GameObject *gameObject = new Tobes::GameObject();
				tempBlocksZ[z].Init(Block::Brick, gameObject, mesh, mat);
				gameObject->GetTransform()->Translate(Vector3(x, y, z));
			}
			tempBlocksX[x] = tempBlocksZ;
		}
		tempBlocksY[y] = tempBlocksX;
	}
	blocks = tempBlocksY;


	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			for (int z = 0; z < depth; z++)
			{
				//RenderCheck(y, x, z);
			}
		}
	}
}

void Chunk::RenderCheck(int y, int x, int z)
{
	bool render = false;
	if (x > 0)
	{
		if (blocks[y][x - 1][z].m_type == Block::Air)
			render = true;
	}
	if (x < m_width - 1)
	{
		if (blocks[y][x + 1][z].m_type == Block::Air)
			render = true;
	}
	if (x == 0 || x == m_width - 1)
		render = false;
	if (y > 0)
	{
		if (blocks[y - 1][x][z].m_type == Block::Air)
			render = true;
	}
	if (y < m_height - 1)
	{
		if (blocks[y + 1][x][z].m_type == Block::Air)
			render = true;
	}
	if (y == m_height - 1)
		render = false;
	if (y == 0)
		render = true;
	if (z > 0)
	{
		if (blocks[y][x][z - 1].m_type == Block::Air)
			render = true;
	}
	if (z < m_depth - 1)
	{
		if (blocks[y][x][z + 1].m_type == Block::Air)
			render = true;
	}
	if (z == 0 || z == m_depth - 1)
		render = false;
	blocks[y][x][z].m_renderer->SetActive(render);
}
