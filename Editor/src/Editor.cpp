#include "Editor.h"

Tobes::Application* CreateApplication()
{
	return new Editor();
}

void Editor::Startup()
{
	ShowMouse(true);
	m_assetWindow = new AssetWindow();
	m_sceneWindow = new SceneWindow();
	m_gameWindow = new GameWindow();
}

void Editor::OnFileDrop(int count, const char ** paths)
{
	m_assetWindow->OnFileDrop(count, paths);
}

void Editor::Update(float dt)
{
	m_gameWindow->UpdateCamera(m_camera, dt);

	m_assetWindow->Draw();
	m_sceneWindow->Draw();
	m_gameWindow->Draw();
}