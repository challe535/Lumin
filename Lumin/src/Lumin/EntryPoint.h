#pragma once


#ifdef LUMIN_PLATFORM_WINDOWS

extern Lumin::Application* Lumin::CreateApplication();

int main(int argc, char** argv)
{
	Lumin::Log::Init();

	LUM_CORE_CRITICAL("Initalized Log");

	int a = 2;
	LUM_INFO("All good var={0}", a);

	auto app = Lumin::CreateApplication();
	app->Run();
	delete app;
}

#endif