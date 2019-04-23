#pragma once
extern Tobes::Application* Tobes::CreateApplication();

//Main entry point
int main(int argc, char** argv)
{
	auto app = Tobes::CreateApplication();
	app->Run();
	delete app;
	return 0;
}



