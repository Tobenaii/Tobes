#include "GameWindow.h"
#include "Tobes.h"
#include "Tobes/Application.h"
#include <iostream>
#include <math.h>

void GameWindow::Draw()
{
	ImGui::Begin("Game", false, ImGuiWindowFlags_NoBackground);
	Vector2 pos = ImGui::GetWindowPos();
	Vector2 size = ImGui::GetWindowSize();
	Tobes::Application::SetBounds(pos, size);
	ImGui::End();
}

void GameWindow::UpdateCamera(Tobes::Camera * m_camera, float dt)
{
	Tobes::Input* input = Tobes::Input::GetInstance();

	if (input->IsButtonDown(0))
	{
		if (input->GetMouseDeltaX() != 0)
			m_camera->transform->Translate(m_camera->transform->GetRight() * input->GetMouseDeltaX() * -dt);

		if (input->GetMouseDeltaY() != 0) 
			m_camera->transform->Translate(m_camera->transform->GetUp() * input->GetMouseDeltaY() * dt);
	}
	if (input->GetScrollDeltaY() != 0)
		m_camera->transform->Translate(m_camera->transform->GetForward() * input->GetScrollDeltaY() * -1);
	if (input->IsButtonDown(1))
	{
		if (input->GetMouseDeltaX() != 0)
			m_camera->transform->Rotate(Vector3(0,1,0), input->GetMouseDeltaX() * -dt * 0.1f);
		if (input->GetMouseDeltaY() != 0)
			m_camera->transform->Rotate(m_camera->transform->GetRight(), input->GetMouseDeltaY() * -dt * 0.1f);
	}
	if (input->IsButtonDown(2))
		m_camera->transform->Translate(m_camera->transform->GetPosition() * -1);
}
