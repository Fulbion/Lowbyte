#pragma once

#include "Lowbyte/pch.hpp"

#include "Lowbyte/Event/Event.hpp"

namespace lowbyte
{
	class LOWBYTE_API KeyEvent : public Event
	{
	public:
		inline int getKeyCode() const { return m_keyCode; }
		EVENT_CLASS_CATEGORY(CategoryKeyboard | CategoryInput);

	protected:
		KeyEvent(int i_keyCode) : m_keyCode(i_keyCode) {}
		int m_keyCode;
	};

	class LOWBYTE_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int i_keyCode, int i_repeatCount) :
			KeyEvent(i_keyCode), m_repeatCount(i_repeatCount)
		{
		}

		inline int getRepeatCount() const { return m_repeatCount; }

		std::string toString() const override
		{
			std::stringstream sstr;
			sstr << "KeyPressedEvent: " << m_keyCode << " (" << m_repeatCount << " repeats)";
			return sstr.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int m_repeatCount;
	};

	class LOWBYTE_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int i_keyCode) :
			KeyEvent(i_keyCode)
		{
		}

		std::string toString() const override
		{
			std::stringstream sstr;
			sstr << "KeyPressedEvent: " << m_keyCode << " (" << m_repeatCount << " repeats)";
			return sstr.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	};
}