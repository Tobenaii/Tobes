#pragma once
#ifdef TB_PLATFORM_WINDOWS

extern Tobes::Application* Tobes::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Tobes::CreateApplication();
	app->Run();
	delete app;
	return 0;
}
#endif


