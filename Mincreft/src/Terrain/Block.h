#include "Tobes/Common/Component.h"

class Block : public Tobes::Component
{
	friend class Chunk;
private:
	int x;
	int y;
	int z;
	void Generate(int x, int y, int z);
};
