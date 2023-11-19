#pragma once

#include "Lowbyte/pch.hpp"

#include "Lowbyte/Event/Event.hpp"

namespace lowbyte
{
	class LOWBYTE_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float i_x, float i_y) :
			m_mouseX(i_x), m_mouseY(i_y)
		{
		}

		inline float getX() const { return m_mouseX; }
		inline float getY() const { return m_mouseY; }
		
		std::string toString() const override
		{
			std::stringstream sstr;
			sstr << "MouseMovedEvent: " << m_mouseX << ", " << m_mouseY;
			return sstr.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(CategoryMouse | CategoryInput)

	private:
		float m_mouseX, m_mouseY;
	};
	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(const float i_offsetX, const float i_offsetY) :
			m_offsetX(i_offsetX), m_offsetY(i_offsetY)
		{
		}

		float getOffsetX() const { return m_offsetX; }
		float getOffsetY() const { return m_offsetY; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << this->getOffsetX() << ", " << this->getOffsetY();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(CategoryMouse | CategoryInput)

	private:
		float m_offsetX, m_offsetY;
	};

	class MouseButtonEvent : public Event
	{
	public:
		int GetMouseButton() const { return m_button; }
		EVENT_CLASS_CATEGORY(CategoryMouse | CategoryInput | CategoryMouseButton)
	
	protected:
		MouseButtonEvent(const int i_button)
			: m_button(i_button) {}

		int m_button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(const int button)
			: MouseButtonEvent(button) {}

		std::string toString() const override
		{
			std::stringstream sstr;
			sstr << "MouseButtonPressedEvent: " << m_button;
			return sstr.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(const int i_button)
			: MouseButtonEvent(i_button)
		{
		}

		std::string toString() const override
		{
			std::stringstream sstr;
			sstr << "MouseButtonReleasedEvent: " << m_button;
			return sstr.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}