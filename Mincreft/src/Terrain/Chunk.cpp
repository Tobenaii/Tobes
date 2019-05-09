#include "Chunk.h"
#include "Block.h"
#include <iostream>
#include "Tobes/Common/GameObject.h"

void Chunk::Generate(int width, int height, int depth)
{
	Tobes::GameObject*** tempBlocksY = new Tobes::GameObject**[height];
	for (int y = 0; y < height; y++)
	{
		Tobes::GameObject** tempBlocksX = new Tobes::GameObject*[width];
		for (int x = 0; x < width; x++)
		{
			Tobes::GameObject* tempBlocksZ = new Tobes::GameObject[depth];
			for (int z = 0; z < depth; z++)
			{
				Block* block = tempBlocksZ[z].AddComponent<Block>();
				block->Generate(x, y, z);
				std::cout << x << "," << y << "," << z << std::endl;
			}
			tempBlocksX[x] = tempBlocksZ;
		}
		tempBlocksY[y] = tempBlocksX;
	}
	blocks = tempBlocksY;
}
