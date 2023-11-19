#pragma once

#include <GLFW/glfw3.h>

#include "Lowbyte/Window.hpp"
#include "Lowbyte/Log.hpp"

namespace lowbyte
{
	namespace Windows
	{
		class Window : public lowbyte::Window
		{
		public:
			Window(const WindowProps& i_props);
			virtual ~Window();

			void onUpdate() override;

			inline unsigned int getWidth() const override { return m_data.width; }
			inline unsigned int getHeight() const override { return m_data.height; }

			inline void setEventCallback(const EventCallbackFunction& i_callback) override { m_data.eventCallback = i_callback; }

			void setVSync(bool i_vSync) override;
			bool isVSync() const override;

		private:
			virtual void init(const WindowProps& i_props);
			virtual void release();

			GLFWwindow* m_window;

			struct WindowData
			{
				unsigned int width;
				unsigned int height;
				std::string title;
				bool vSync;
				EventCallbackFunction eventCallback;
			};

			WindowData m_data;
		};
	}
}