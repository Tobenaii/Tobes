#pragma once
extern Tobes::Application* CreateApplication();

//Main entry point
int main(int argc, char** argv)
{
	auto app = CreateApplication();
	app->Run();
	delete app;
	return 0;
}



