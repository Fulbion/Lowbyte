#pragma once

#include "Lowbyte/Core.hpp"
#include "Lowbyte/Event/Event.hpp"
#include "Lowbyte/Event/AppEvent.hpp"
#include "Lowbyte/Event/KeyEvent.hpp"
#include "Lowbyte/Event/MouseEvent.hpp"
#include "Lowbyte/Window.hpp"

namespace lowbyte
{
	class LOWBYTE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();

		void onEvent(Event& i_event);

	private:
		bool onWindowClose(WindowCloseEvent& i_event);

		std::unique_ptr<Window> m_window;
		bool m_isRunning = true;
	};

	Application* createApp();
}