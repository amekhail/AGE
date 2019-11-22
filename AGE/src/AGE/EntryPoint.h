#pragma once

#ifdef AGE_PLATFORM_WINDOWS

extern AGE::Application* AGE::CreateApplication();

int main(int argc, char**argv)
{
	printf("AGE GAME ENGINE!\n");
	auto app = AGE::CreateApplication();
	app->Run();
	delete app;
}

#endif