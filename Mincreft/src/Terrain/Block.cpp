#include "Block.h"
#include "Tobes/Common/Scene.h"
#include "Tobes/Common/GameObject.h"
#include "Tobes/Renderer3D/Model.h"
#include "Tobes/Common/Components/Transform.h"

void Block::Generate(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	Tobes::Model* model = m_gameObject->AddComponent<Tobes::Model>();
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

	model->CreateMesh(verts, 8, indices, 12);
	model->GetTransform()->SetPosition(Vector3(x, y, z));
}
