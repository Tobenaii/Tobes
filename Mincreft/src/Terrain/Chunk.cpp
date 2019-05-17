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
}