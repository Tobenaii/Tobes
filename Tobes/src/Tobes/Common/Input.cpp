#include "Input.h"
#include <GLFW/glfw3.h>
#include <iostream>

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
	for (int i = 0; i <= KeyCode_LAST; i++)
	{
		m_curKeys[i] = m_prevKeys[i] = glfwGetKey(glfwGetCurrentContext(), i);
	}

	auto KeyCallback = [](GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (key == -1)
			return;
		Input::GetInstance()->m_curKeys[key] = action;
	};

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

	auto MouseEnteredCallback = [](GLFWwindow*, int entered)
	{
		Input::GetInstance()->m_mouseEntered = true;
	};

	glfwSetCursorPosCallback(glfwGetCurrentContext(), MouseMoveCallback);
	glfwSetCursorEnterCallback(glfwGetCurrentContext(), MouseEnteredCallback);
	glfwSetKeyCallback(glfwGetCurrentContext(), KeyCallback);
}

bool Input::IsKeyDown(int key)
{
	return m_curKeys[key] == GLFW_PRESS || m_curKeys[key] == GLFW_REPEAT;
}

bool Input::WasKeyPressed(int key)
{
	return m_curKeys[key] == GLFW_PRESS && m_prevKeys[key] == GLFW_RELEASE;
}

double Input::GetMouseDeltaX()
{
	return m_mouseX - m_prevMouseX;
}

double Input::GetMouseDeltaY()
{
	return m_mouseY - m_prevMouseY;
}

void Input::Clear()
{
	for (int i = 0; i < KeyCode_LAST; i++)
	{
		m_prevKeys[i] = m_curKeys[i];
		m_curKeys[i] = glfwGetKey(glfwGetCurrentContext(), i);
	}
	m_prevMouseX = m_mouseX;
	m_prevMouseY = m_mouseY;
}
