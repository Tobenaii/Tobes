#include "Application.h"
#include <stdio.h>
#include <GLFW/glfw3.h>
#include "Renderer/Shader.h"
#include <iostream>
#include "Renderer/GameObject.h"
#include "Renderer/Mesh.h"

namespace Tobes
{
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
		m_camera = new Camera();
		m_renderer = new Renderer(m_window);
		m_renderer->Initialize();
		std::cout << "OpenGL Version: ";
		std::cout << glGetString(GL_VERSION) << std::endl;


		//Main Program Loop
		Startup();
		double prevTime = glfwGetTime();
		double curTime = 0;
		double deltaTime = 0;
		while (!glfwWindowShouldClose(m_window))
		{
			curTime = glfwGetTime();
			deltaTime = curTime - prevTime;
			prevTime = curTime;
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glfwPollEvents();
			Update(deltaTime);
			Draw();
			glfwSwapBuffers(m_window);
		}

	}
	void Application::Init()
	{
		std::cout << "Starting Tobes" << std::endl;
		if (!glfwInit())
		{
			std::cout << "Failed to initialize glfw" << std::endl;
		}
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
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
}
