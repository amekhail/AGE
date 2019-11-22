#include "Log.h"


namespace AGE
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$"); //check wiki... this is a temp pattern
		s_CoreLogger = spdlog::stdout_color_mt("AGE");
		s_CoreLogger->set_level(spdlog::level::trace);

		

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}