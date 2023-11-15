#include <Lowbyte.hpp>

class Sandbox : public lowbyte::Application
{
public:
	Sandbox() {}
	~Sandbox() {}
};

lowbyte::Application* lowbyte::createApp()
{
	return new Sandbox();
}