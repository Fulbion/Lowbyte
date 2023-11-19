#pragma once

#ifdef LB_PLATFORM_WINDOWS

extern lowbyte::Application* lowbyte::createApp();

int main(int argc, char** argv)
{
	lowbyte::Log::init();
	LB_CORE_WARN("Initialized log!");

	auto app = lowbyte::createApp();
	app->run();
	delete app;
	return 0;
}

#endif // LB_PLATFORM_WINDOWS