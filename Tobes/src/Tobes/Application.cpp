#include "Application.h"
#include <stdio.h>
#include <GLFW/glfw3.h>
#include "Renderer/Shader.h"
#include <iostream>
#include "Tobes/Common/GameObject.h"
#include "Tobes/Renderer/Renderer.h"
#include "Tobes/Renderer/Camera.h"
#include "Tobes/Common/Input.h"
#include "Tobes/Common/Scene.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

namespace Tobes
{
	Scene* Application::m_scene = nullptr;

	Application::Application()
	{

	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		Init();
		CreateWindow();
		ImGui::CreateContext();
		ImGui::StyleColorsDark();
		ImGui_ImplGlfw_InitForOpenGL(m_window, true);

		//Disabled cursor for virtual infinite mouse movement
		glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		//Initialize everything
		m_renderer = new Renderer(m_window);
		m_scene = new Scene();
		m_renderer->Initialize();
		std::cout << "OpenGL Version: ";
		const char* version = "#version 130";
		std::cout << glGetString(GL_VERSION) << std::endl;
		ImGui_ImplOpenGL3_Init(version);

		ImVec4 clearColour = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

		//Enable alpha blending and depth test
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_DEPTH_TEST);
		GameObject* camera = new GameObject();
		m_camera = camera->AddComponent<Camera>();
		//Main Program Loop
		Startup();

		//Initialize values for frame time
		double prevTime = glfwGetTime();
		double curTime = 0;
		double deltaTime = 0;
		bool showPreview = false;
		double fps = 0;
		double timer = 0;
		Input::GetInstance()->AddApplication(this);
		//Main game loop
		while (!glfwWindowShouldClose(m_window))
		{

			curTime = glfwGetTime();
			deltaTime = curTime - prevTime;
			if (deltaTime > 0.1f)
				deltaTime = 0.1f;
			fps += 1;
			timer += deltaTime;
			if (timer >= 1)
			{
				timer = 0;
				std::cout << "FPS: " << fps << std::endl;
				fps = 0;
			}
			prevTime = curTime;
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glfwPollEvents();
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();
			Update((float)deltaTime);
			m_scene->Update((float)deltaTime);
			Draw();
			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
			Input::GetInstance()->Clear();
			glfwSwapBuffers(m_window);
		}
	}

	Scene * Application::GetCurrentScene()
	{
		return m_scene;
	}

	void Application::Init()
	{
		std::cout << "Starting Tobes" << std::endl;
		if (!glfwInit())
		{
			std::cout << "Failed to initialize glfw" << std::endl;
		}

		//Set glfw window properties
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glEnable(GL_CULL_FACE);
		glCullFace(GL_FRONT);
		glFrontFace(GL_CCW);
	}
	void Application::CreateWindow()
	{
		m_window = glfwCreateWindow(800, 800, "TestApp", NULL, NULL);
		glfwMakeContextCurrent(m_window);
	}
	void Application::Cleanup()
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}

	void Application::Draw()
	{
		m_scene->Draw(m_renderer, m_camera);
	}
}

