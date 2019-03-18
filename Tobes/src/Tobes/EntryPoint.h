#pragma once
extern Tobes::Application* Tobes::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Tobes::CreateApplication();
	app->Run();
	delete app;
	return 0;
}



