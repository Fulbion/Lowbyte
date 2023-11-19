#include "Lowbyte/pch.hpp"

#include "Lowbyte/Application.hpp"

#include "Lowbyte/Event/AppEvent.hpp"
#include "Lowbyte/Log.hpp"

#include <GLFW/glfw3.h>

namespace lowbyte
{
	Application::Application()
	{
		m_window = std::unique_ptr<Window>(Window::create());
	}

	Application::~Application()
	{
	}

	void Application::run()
	{
		while (this->m_isRunning)
		{
			glClearColor(1, 0.65, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			this->m_window->onUpdate();
		}
	}
}