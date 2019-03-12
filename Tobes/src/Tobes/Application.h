#pragma once
#include "Core.h"

struct GLFWwindow;

namespace Tobes
{
	class TOBES_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
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
	};
	Application* CreateApplication();
}
