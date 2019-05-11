#pragma once
#include "Tobes/Core.h"

struct GLFWwindow;

namespace Tobes
{
	struct Instance;
	class Renderer
	{
		friend class MeshRenderer;
		friend class Application;
		friend class Scene;

	private:
		GLFWwindow* m_window;

	private:
		Renderer(GLFWwindow* window);
		void Initialize();
		void DrawMesh(Mesh* mesh);
		void DrawInstancedMesh(Instance* instance);

	};
}
