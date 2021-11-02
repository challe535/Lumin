#pragma once


#ifdef LUMIN_PLATFORM_WINDOWS

extern Lumin::Application* Lumin::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Lumin::CreateApplication();
	app->Run();
	delete app;
}

#endif