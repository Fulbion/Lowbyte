#pragma once

#include "Lowbyte/Core.hpp"
#include "Lowbyte/Event/Event.hpp"
#include "Lowbyte/Window.hpp"

namespace lowbyte
{
	class LOWBYTE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();

	private:
		std::unique_ptr<Window> m_window;
		bool m_isRunning = true;
	};

	Application* createApp();
}