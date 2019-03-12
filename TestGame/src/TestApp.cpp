#include "..\..\Tobes\src\Tobes\Application.h"
#include "TestApp.h"
#include <iostream>

Tobes::Application* Tobes::CreateApplication()
{
	return new TestApp();
}

TestApp::TestApp()
{
}

TestApp::~TestApp()
{
}

void TestApp::Update(float dt)
{
	std::cout << dt << std::endl;
}
