#pragma once
#include <Tobes.h>
#include <vector>

class ContentPipeline : public Tobes::Application
{
private:
	virtual void Startup();
	virtual void OnFileDrop(int count, const char ** paths);
	virtual void Draw();
	virtual void Update(float dt);

private:
	Tobes::Model* m_currentModel;
	std::vector<Tobes::Texture*> m_textures;
	std::vector<Tobes::Material*> m_materials;
	std::vector<bool> m_meshBools;
};
