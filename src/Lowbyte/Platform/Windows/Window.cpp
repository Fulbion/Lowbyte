#include "Lowbyte/pch.hpp"

#include "Lowbyte/Platform/Windows/Window.hpp"

namespace lowbyte
{
	Window* Window::create(const WindowProps& i_props)
	{
		return new Windows::Window(i_props);
	}

	namespace Windows
	{
		static bool s_glfwInitialized = false;

		Window::Window(const WindowProps& i_props)
		{
			this->init(i_props);
		}

		Window::~Window()
		{
			this->release();
		}

		void Window::init(const WindowProps& i_props)
		{
			this->m_data.width = i_props.width;
			this->m_data.height = i_props.height;
			this->m_data.title = i_props.title;

			LB_CORE_TRACE("Creating window {0} ({1}, {2})", this->m_data.title, this->m_data.width, this->m_data.height);

			if (!s_glfwInitialized)
			{
				int result = glfwInit();

				if (result == GLFW_FALSE)
				{
					LB_CORE_FATAL("Failed to initialize GLFW!");
				}

				else
				{
					LB_CORE_INFO("Initialized GLFW successfully!");
					s_glfwInitialized = true;
				}
			}

			this->m_window = glfwCreateWindow(this->m_data.width, this->m_data.height, this->m_data.title.c_str(), nullptr, nullptr);
			glfwMakeContextCurrent(this->m_window);
			glfwSetWindowUserPointer(this->m_window, &this->m_data);
			this->setVSync(false);
		}

		void Window::release()
		{
			glfwDestroyWindow(this->m_window);
		}

		void Window::onUpdate()
		{
			glfwPollEvents();
			glfwSwapBuffers(this->m_window);
		}

		void Window::setVSync(bool i_vSync)
		{
			if (i_vSync)
				glfwSwapInterval(1);
			else
				glfwSwapInterval(0);

			this->m_data.vSync = i_vSync;
		}

		bool Window::isVSync() const
		{
			return this->m_data.vSync;
		}
	}
}