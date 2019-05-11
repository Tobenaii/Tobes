#include "Chunk.h"
#include <iostream>
#include "Tobes/Common/GameObject.h"
#include "Tobes/Renderer3D/Components/MeshRenderer.h"
#include "Tobes/Common/Components/Transform.h"

void Chunk::Generate(int width, int height, int depth, Tobes::Mesh* mesh, Tobes::Material* mat)
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
				Tobes::GameObject *block = new Tobes::GameObject();
				Tobes::MeshRenderer* renderer = block->AddComponent<Tobes::MeshRenderer>();
				renderer->SetMesh(mesh);
				renderer->SetMaterial(mat);
				block->GetTransform()->Translate(Vector3(x * 2, y * 2, z * 2));
			}
			tempBlocksX[x] = tempBlocksZ;
		}
		tempBlocksY[y] = tempBlocksX;
	}
	blocks = tempBlocksY;
}
