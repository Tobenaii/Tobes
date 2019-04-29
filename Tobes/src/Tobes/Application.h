#pragma once
#include "Renderer/Renderer.h"
#include "Renderer/Camera.h"

struct GLFWwindow;

namespace Tobes
{
	class Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		virtual void Startup() {};
		virtual void Update(float dt) {}
		virtual void Draw() {}
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
