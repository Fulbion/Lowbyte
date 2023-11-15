#pragma once

#include "Lowbyte/Application.hpp"

#ifdef LB_PLATFORM_WINDOWS

extern lowbyte::Application* lowbyte::createApp();

int main(int argc, char** argv)
{
	auto app = lowbyte::createApp();
	app->run();
	delete app;
	return 0;
}

#endif // LB_PLATFORM_WINDOWS