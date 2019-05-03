#pragma once
#include "Tobes/Core.h"
#include <GLFW/glfw3.h>
#include "Renderer.h"
#include "Camera.h"

namespace Tobes
{
	class TOBES_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		virtual void Startup() {};
		virtual void Update(float dt) {}
		virtual void Draw() {}
		virtual void OnFileDrop(int count, const char ** paths) {}
		void ClearScreen() {}

	private:
		void Init();
		void CreateWindow();
		void Cleanup();

	private:
		GLFWwindow* m_window;
	protected:
		Renderer* m_renderer;
		Camera* m_camera;
	};

	Application* CreateApplication();
}
