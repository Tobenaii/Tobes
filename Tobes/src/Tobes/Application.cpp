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
#include "Tobes/Renderer3D/Components/MeshRenderer.h"
#include "Tobes/Renderer/Material.h"
#include "Tobes/Renderer3D/Mesh.h"
#include "Tobes/Renderer/Texture.h"
#include "Tobes/Common/Components/Transform.h"
#include <math.h>

namespace Tobes
{
	Scene* Application::m_scene = nullptr;
	Vector2 Application::m_position = Vector2(0, 0);
	Vector2 Application::m_extents = Vector2(0, 0);
	int Application::windowWidth = 0;
	int Application::windowHeight = 0;

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
		GameObject* camera = new GameObject("MainCamera");
		m_camera = camera->AddComponent<Camera>();
		//Main Program Loop

		//Initialize values for frame time
		double prevTime = glfwGetTime();
		double curTime = 0;
		double deltaTime = 0;
		bool showPreview = false;
		double fps = 0;
		double timer = 0;
		Input::GetInstance()->AddApplication(this);
		ImGui::GetIO().ConfigWindowsMoveFromTitleBarOnly = true;
		glfwPollEvents();
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		Startup();

		m_maps.push_back(".\\content\\skybox\\bluefreeze_rt.png");
		m_maps.push_back(".\\content\\skybox\\bluefreeze_lf.png");
		m_maps.push_back(".\\content\\skybox\\bluefreeze_up.png");
		m_maps.push_back(".\\content\\skybox\\bluefreeze_dn.png");
		m_maps.push_back(".\\content\\skybox\\bluefreeze_bk.png");
		m_maps.push_back(".\\content\\skybox\\bluefreeze_ft.png");

		m_skybox = new GameObject();
		m_skyboxRenderer = m_skybox->AddComponent<MeshRenderer>();
		Material* material = new Material();
		Shader* shader = new Shader();
		shader->LoadVertexShader(".\\content\\shaders\\vertex_sky.txt");
		shader->LoadFragmentShader(".\\content\\shaders\\frag_sky.txt");
		shader->LinkProgram();
		material->LoadShader(shader);
		Mesh* mesh = new Mesh(Primitive::Skybox);
		m_skyboxRenderer->SetMesh(mesh);
		m_skyboxRenderer->SetMaterial(material);
		Texture* texture = new Texture(&m_maps[0]);
		material->SetDiffuseMap(texture);
		m_skybox->m_transform->Scale(Vector3(1000, 1000, 1000));

		//Main game loop
		while (!glfwWindowShouldClose(m_window))
		{
			m_camera->SetPerspective(1.5708f, m_extents.x / m_extents.y, 0.1f, 10000.0f);
			std::cout << m_extents.x / m_extents.y << std::endl;
			glfwPollEvents();
			glfwGetWindowSize(m_window, &windowWidth, &windowHeight);
			Vector2 mousePos = Input::GetInstance()->GetMousePos();
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
			ImGui_ImplOpenGL3_NewFrame();
			ImGui::NewFrame();
			if (mousePos.x > m_position.x && mousePos.x < m_position.x + m_extents.x && mousePos.y > m_position.y && mousePos.y < m_position.y + m_extents.y)
				ImGui::GetIO().WantCaptureMouse = false;
			Update((float)deltaTime);
			m_scene->Update((float)deltaTime);
			m_skyboxRenderer->DrawSkybox(m_renderer, m_camera);
			Draw();
			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
			Input::GetInstance()->Clear();
			glfwSwapBuffers(m_window);
		}
	}

	Scene* Application::GetCurrentScene()
	{
		return m_scene;
	}

	void Application::SetBounds(Vector2 position, Vector2 extents)
	{
		m_position = position;
		m_extents = extents;
		glViewport(m_position.x, abs(m_position.y - windowHeight) - m_extents.y, m_extents.x, m_extents.y);
	}

	void Application::ShowMouse(bool show)
	{
		glfwSetInputMode(m_window, GLFW_CURSOR, ((!show)?GLFW_CURSOR_DISABLED:GLFW_CURSOR_NORMAL));
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
		//glEnable(GL_CULL_FACE);
		//glCullFace(GL_FRONT);
		//glFrontFace(GL_CCW);
	}
	void Application::CreateWindow()
	{
		m_window = glfwCreateWindow(1280, 720, "TestApp", NULL, NULL);
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

