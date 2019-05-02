#pragma once
#include "Tobes/Common/GameObject.h"

class Model : public GameObject
{
public:
	void LoadModel(std::string path);
	void SetGlobalMaterial(Material* mat);
	int GetMeshCount();
	void Draw(Renderer* renderer, Camera* camera);

private:
	std::vector<Mesh*> m_meshes;
};