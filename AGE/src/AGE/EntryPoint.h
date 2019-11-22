#pragma once

#ifdef AGE_PLATFORM_WINDOWS

extern AGE::Application* AGE::CreateApplication();

int main(int argc, char**argv)
{
	AGE::Log::Init();
	AGE_CORE_WARN("Poopoo peepee");
	AGE_INFO("gigga var = {0}", 5);

	auto app = AGE::CreateApplication();
	app->Run();
	delete app;
}

#endif

