#include "GameWindow.h"
#include "Tobes.h"
#include "Tobes/Application.h"
#include <iostream>
#include <math.h>

void GameWindow::Draw()
{
	ImGui::Begin("Game");
	Vector2 pos = ImGui::GetWindowPos();
	Vector2 size = ImGui::GetWindowSize();
	std::cout << pos.y << std::endl;
	Tobes::Application::SetBounds(pos, size);
	ImGui::End();
}
