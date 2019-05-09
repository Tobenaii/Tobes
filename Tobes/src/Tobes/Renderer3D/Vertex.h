#pragma once
#include "Tobes/Common/Math/Vector2.h"
#include "Tobes/Common/Math/Vector3.h"
#include "Tobes/Common/Math/Vector4.h"

struct Vertex
{
	Vertex()
	{
		position = Vector4(0, 0, 0, 1);
		textureCoord = Vector2(0, 0);
		normal = Vector3(0, 0, 0);
	}
	Vertex(Vector4 pos, Vector2 texCoord, Vector3 norm)
	{
		position = pos;
		textureCoord = texCoord;
		normal = norm;
	}
	Vector4 position;
	Vector2 textureCoord;
	Vector3 normal;
};
