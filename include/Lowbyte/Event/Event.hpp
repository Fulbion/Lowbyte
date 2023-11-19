#pragma once

#include "Lowbyte/pch.hpp"

#include "Lowbyte/Core.hpp"

namespace lowbyte
{
	enum class EventType
	{
		None = 0,

		WindowClose,
		WindowResize,
		WindowFocus,
		WindowLostFocus,
		WindowMoved,

		AppTick,
		AppUpdate,
		AppRender,

		KeyPressed,
		KeyReleased,

		MouseButtonPressed,
		MouseButtonReleased,
		MouseMoved,
		MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		CategoryApp = BIT(0),
		CategoryInput = BIT(1),
		CategoryKeyboard = BIT(2),
		CategoryMouse = BIT(3),
		CategoryMouseButton = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType getStaticType() { return EventType::type; }\
								virtual EventType getEventType() const override { return getStaticType(); }\
								virtual const char* getName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }

	class LOWBYTE_API Event
	{
	public:
		virtual EventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual int getCategoryFlags() const = 0;
		virtual std::string toString() const { return this->getName(); };

		inline bool isInCategory(EventCategory& i_category)
		{
			return this->getCategoryFlags() & i_category;
		}

	protected:
		bool m_handled = false;

	private:
		friend class EventDispatcher;
	};

	class LOWBYTE_API EventDispatcher
	{
		template<typename T>
		using EventFunction = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& i_event) :
			m_event(i_event)
		{
		}

		template<typename T>
		bool dispatch(EventFunction<T> i_function)
		{
			if (m_event.getEventType() == T::getStaticType())
			{
				m_event.m_handled = i_function(*(T*)&m_event);
				return true;
			}

			return false;
		}

	private:
		Event& m_event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.toString();
	}
}