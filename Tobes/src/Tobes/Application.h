#pragma once
#include "Core.h"
#include "Renderer/Renderer.h"
#include "Renderer/Camera.h"

struct GLFWwindow;

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
		void ClearScreen() {}

	private:
		void Init();
		void CreateWindow();
		void Cleanup();

	private:
		double m_dt;
		GLFWwindow* m_window;
	protected:
		Renderer* m_renderer;
		Camera* m_camera;
	};
	Application* CreateApplication();
}
