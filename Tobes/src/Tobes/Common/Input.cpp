#include "Input.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "Tobes/imgui/imgui.h"
#include "Application.h"

Input* Input::m_instance = nullptr;

Input* Input::GetInstance()
{
	if (m_instance == nullptr)
		m_instance = new Input();
	return m_instance;
}

Input::Input()
{
	m_firstMouseMove = true;
	m_curKeys = new int[KeyCode_LAST];
	m_prevKeys = new int[KeyCode_LAST];

	m_curButtons = new int[2];
	m_prevButtons = new int[2];

	for (int i = 0; i <= KeyCode_LAST; i++)
	{
		m_curKeys[i] = m_prevKeys[i] = glfwGetKey(glfwGetCurrentContext(), i);
	}

	for (int i = 0; i <= 2; i++)
	{
		m_curButtons[i] = m_prevButtons[i] = glfwGetMouseButton(glfwGetCurrentContext(), i);
	}

	//Callback for key press
	auto KeyCallback = [](GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (key == -1)
			return;
		Input::GetInstance()->m_curKeys[key] = action;
	};

	//Callback for mouse move
	auto MouseMoveCallback = [](GLFWwindow*, double x, double y)
	{
		if (Input::GetInstance()->m_mouseEntered || Input::GetInstance()->m_firstMouseMove)
		{
			Input::GetInstance()->m_prevMouseX = x;
			Input::GetInstance()->m_prevMouseY = y;
			Input::GetInstance()->m_mouseEntered = false;
			Input::GetInstance()->m_firstMouseMove = false;
		}
		Input::GetInstance()->m_mouseX = x;
		Input::GetInstance()->m_mouseY = y;
	};

	//Callback for mouse entered the screen
	auto MouseEnteredCallback = [](GLFWwindow*, int entered)
	{
		Input::GetInstance()->m_mouseEntered = true;
	};

	auto MouseClickCallback = [](GLFWwindow*, int button, int action, int c)
	{
		Input::GetInstance()->m_curButtons[button] = action;
	};

	auto FileDropCallback = [](GLFWwindow* window, int count, const char** paths)
	{
		for (auto app : Input::GetInstance()->m_applications)
		{
			app->OnFileDrop(count, paths);
		}
	};

	auto MouseScrollCallback = [](GLFWwindow*, double x, double y)
	{
		Input::GetInstance()->m_scrollY = y;
	};

	//Assign callbacks to glfw
	glfwSetCursorPosCallback(glfwGetCurrentContext(), MouseMoveCallback);
	glfwSetCursorEnterCallback(glfwGetCurrentContext(), MouseEnteredCallback);
	glfwSetKeyCallback(glfwGetCurrentContext(), KeyCallback);
	glfwSetDropCallback(glfwGetCurrentContext(), FileDropCallback);
	glfwSetMouseButtonCallback(glfwGetCurrentContext(), MouseClickCallback);
	glfwSetScrollCallback(glfwGetCurrentContext(), MouseScrollCallback);
}

bool Input::IsKeyDown(int key)
{
	return m_curKeys[key] == GLFW_PRESS || m_curKeys[key] == GLFW_REPEAT;
}

bool Input::WasKeyPressed(int key)
{
	return m_curKeys[key] == GLFW_PRESS && m_prevKeys[key] == GLFW_RELEASE;
}

bool Input::IsButtonDown(int button)
{
	if (ImGui::GetIO().WantCaptureMouse)
		return false;
	return m_curButtons[button] == GLFW_PRESS || m_curButtons[button] == GLFW_REPEAT;
}

bool Input::WasButtonPressed(int button)
{
	if (ImGui::GetIO().WantCaptureMouse)
		return false;
	return m_curButtons[button] == GLFW_PRESS && m_curButtons[button] == GLFW_RELEASE;
}

double Input::GetMouseDeltaX()
{
	return m_mouseX - m_prevMouseX;
}

double Input::GetMouseDeltaY()
{
	return m_mouseY - m_prevMouseY;
}

double Input::GetScrollDeltaY()
{
	return m_scrollY;
}

void Input::AddApplication(Application * app)
{
	m_applications.push_back(app);
}

void Input::Clear()
{
	for (int i = 0; i < KeyCode_LAST; i++)
	{
		m_prevKeys[i] = m_curKeys[i];
		m_curKeys[i] = glfwGetKey(glfwGetCurrentContext(), i);
	}
	for (int i = 0; i < 2; i++)
	{
		m_prevButtons[i] = m_curButtons[i];
		m_curButtons[i] = glfwGetMouseButton(glfwGetCurrentContext(), i);
	}
	m_prevMouseX = m_mouseX;
	m_prevMouseY = m_mouseY;

	m_scrollY = 0;
}
