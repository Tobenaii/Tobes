#pragma once
#include "Tobes/Core.h"
#include "Tobes/Common/Math/Vector2.h"
#include <vector>

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
		static void SetBounds(Vector2 position, Vector2 extents);

		static int windowWidth;
		static int windowHeight;

	protected:
		Camera* m_camera;
		void ShowMouse(bool show);

	private:
		void Init();
		void CreateWindow();
		void Cleanup();
		void Draw();
		GameObject* m_skybox;
		MeshRenderer* m_skyboxRenderer;
		std::vector<std::string> m_maps;

	protected:
		GLFWwindow* m_window;
		Renderer* m_renderer;
		static Scene* m_scene;
		static Vector2 m_position;
		static Vector2 m_extents;
	};

	Application* CreateApplication();
}
