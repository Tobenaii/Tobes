#include "Application.h"
#include <stdio.h>
#include <GLFW/glfw3.h>

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

		//Main Program Loop
		while (!glfwWindowShouldClose(m_window))
		{
			double prevTime = glfwGetTime();
			glfwPollEvents();
			Update(m_dt);
			m_dt = glfwGetTime() - prevTime;
			glfwSwapBuffers(m_window);
		}

	}
	void Application::Init()
	{
		printf("Starting Tobes");
		if (!glfwInit())
		{
			printf("Failed to initialize glfw");
		}
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
