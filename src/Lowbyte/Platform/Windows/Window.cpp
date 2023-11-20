#include "Lowbyte/pch.hpp"

#include "Lowbyte/Platform/Windows/Window.hpp"

#include "Lowbyte/Event/AppEvent.hpp"
#include "Lowbyte/Event/KeyEvent.hpp"
#include "Lowbyte/Event/MouseEvent.hpp"

namespace lowbyte
{
	Window* Window::create(const WindowProps& i_props)
	{
		return new Windows::Window(i_props);
	}

	namespace Windows
	{
		static bool s_glfwInitialized = false;

		static void s_glfwErrorCallback(int i_error, const char* i_description)
		{
			LB_CORE_ERROR("GLFW Error {0}: {1}", i_error, i_description);
		}

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

				glfwSetErrorCallback(s_glfwErrorCallback);
			}

			this->m_window = glfwCreateWindow(this->m_data.width, this->m_data.height, this->m_data.title.c_str(), nullptr, nullptr);
			glfwMakeContextCurrent(this->m_window);
			glfwSetWindowUserPointer(this->m_window, &this->m_data);
			this->setVSync(false);

			glfwSetWindowSizeCallback(m_window, [](GLFWwindow* i_window, int i_width, int i_height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(i_window);
				data.width = i_width;
				data.height = i_height;
					
				WindowResizeEvent event(i_width, i_height);
				data.eventCallback(event);
			});
			
			glfwSetWindowCloseCallback(m_window, [](GLFWwindow* i_window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(i_window);
				WindowCloseEvent event;
				data.eventCallback(event);
			});

			glfwSetKeyCallback(m_window, [](GLFWwindow* i_window, int i_key, int i_scancode, int i_action, int i_mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(i_window);

				switch (i_action)
				{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(i_key, 0);
					data.eventCallback(event);
					break;
				}

				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(i_key);
					data.eventCallback(event);
					break;
				}

				case GLFW_REPEAT:
				{
					KeyPressedEvent event(i_key, 1);
					data.eventCallback(event);
					break;
				}
				}
			});

			glfwSetMouseButtonCallback(m_window, [](GLFWwindow* i_window, int i_button, int i_action, int i_mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(i_window);

				switch (i_action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(i_button);
					data.eventCallback(event);
					break;
				}

				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(i_button);
					data.eventCallback(event);
					break;
				}
				}
			});

			glfwSetScrollCallback(m_window, [](GLFWwindow* i_window, double i_offsetX, double i_offsetY)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(i_window);

				MouseScrolledEvent event((float)i_offsetX, (float)i_offsetY);
				data.eventCallback(event);

			});

			glfwSetCursorPosCallback(m_window, [](GLFWwindow* i_window, double i_positionX, double i_positionY)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(i_window);

				MouseMovedEvent event((float)i_positionX, (float)i_positionY);
				data.eventCallback(event);

			});
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