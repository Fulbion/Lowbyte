#include "Lowbyte/pch.hpp"

#include "Lowbyte/Application.hpp"

#include "Lowbyte/Event/AppEvent.hpp"
#include "Lowbyte/Log.hpp"

#include <GLFW/glfw3.h>

#define BIND_EVENT_FUNCTION(x) std::bind(&Application::x, this, std::placeholders::_1)

namespace lowbyte
{
	Application::Application()
	{
		this->m_window = std::unique_ptr<Window>(Window::create());
		this->m_window->setEventCallback(BIND_EVENT_FUNCTION(onEvent));
	}

	Application::~Application()
	{
	}

	void Application::onEvent(Event& i_event)
	{
		EventDispatcher dispatcher(i_event);
		dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FUNCTION(onWindowClose));

		LB_CORE_INFO("{0}", i_event);
	}

	bool Application::onWindowClose(WindowCloseEvent& i_event)
	{
		this->m_isRunning = false;
		return true;
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