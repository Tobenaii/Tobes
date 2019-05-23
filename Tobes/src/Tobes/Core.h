#pragma once

namespace Tobes
{
	class Scene;
	class GameObject;
	class Camera;
	class Shader;
	class Texture;
	class Input;
	class Renderer;
	class Light;
	class Mesh;
	class Model;
	class Application;
	class File;
	class Material;
	class Component;
	class MeshRenderer;
}

#ifdef TB_BUILD_DLL
#define TOBES_API __declspec(dllexport)
#else
#define TOBES_API __declspec(dllimport)
#endif
