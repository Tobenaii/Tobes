#pragma once
#include "Tobes/Core.h"

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
		virtual void OnFileDrop(int count, const char ** paths) {}
		static Scene* GetCurrentScene();

	protected:
		Camera* m_camera;

	private:
		void Init();
		void CreateWindow();
		void Cleanup();
		void Draw();

	private:
		GLFWwindow* m_window;
		Renderer* m_renderer;
		static Scene* m_scene;
	};

	Application* CreateApplication();
}
