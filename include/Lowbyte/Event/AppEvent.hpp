#pragma once

#include "Lowbyte/pch.hpp"

#include "Lowbyte/Event/Event.hpp"

namespace lowbyte
{
	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int i_width, unsigned int i_height)
			: m_width(i_width), m_height(i_height) {}

		unsigned int getWidth() const { return m_width; }
		unsigned int getHeight() const { return m_height; }

		std::string toString() const override
		{
			std::stringstream sstr;
			sstr << "WindowResizeEvent: " << m_width << ", " << m_height;
			return sstr.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(CategoryApp)
	
	private:
		unsigned int m_width, m_height;
	};

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(CategoryApp)
	};

	class AppTickEvent : public Event
	{
	public:
		AppTickEvent() = default;

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(CategoryApp)
	};

	class AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() = default;

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(CategoryApp)
	};

	class AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() = default;

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(CategoryApp)
	};
}