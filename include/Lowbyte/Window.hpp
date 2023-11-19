#pragma once

#include "Lowbyte/pch.hpp"

#include "Lowbyte/Core.hpp"
#include "Lowbyte/Event/Event.hpp"

namespace lowbyte
{
	struct WindowProps
	{
		unsigned int width;
		unsigned int height;
		std::string title;

		WindowProps(unsigned int i_width = 1280, unsigned int i_height = 720, const std::string& i_title = "Lowbyte") :
			width(i_width),
			height(i_height),
			title(i_title)
		{
		}
	};

	class LOWBYTE_API Window
	{
	public:
		using EventCallbackFunction = std::function<void(Event&)>;

		// Window() {}
		virtual ~Window() {}

		virtual void onUpdate() = 0;

		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;

		virtual void setEventCallback(const EventCallbackFunction& i_callback) = 0;
		virtual void setVSync(bool i_vSync) = 0;
		virtual bool isVSync() const = 0;

		static Window* create(const WindowProps& i_props = WindowProps());
	};
}