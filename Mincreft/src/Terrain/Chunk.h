#pragma once
#include "Tobes/Common/Component.h"

class Block;
class Scene;

class Chunk : public Tobes::Component
{
friend class Terrain;

private:
	void Generate(int width, int height, int depth);
	Tobes::GameObject*** blocks;
};
