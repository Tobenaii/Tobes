#pragma once
#include "Tobes.h"
#include "Windows/AssetWindow/AssetWindow.h"
#include "Windows/SceneWindow/SceneWindow.h"
#include "Windows/GameWindow/GameWindow.h"
#include "Tobes/EntryPoint.h"

class Editor : public Tobes::Application
{
private:
	AssetWindow* m_assetWindow;
	SceneWindow* m_sceneWindow;
	GameWindow* m_gameWindow;

private:
	virtual void Startup();
	virtual void OnFileDrop(int count, const char ** paths);
	virtual void Update(float dt);
};

