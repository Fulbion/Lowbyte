#pragma once

#include "Lowbyte/Core.hpp"

namespace lowbyte
{
	class LOWBYTE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();

	private:

	};

	Application* createApp();
}