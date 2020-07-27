#ifndef KeyEvent_h
#define KeyEvent_h

#include "Event.h"
#include "Application/KeyCodes.h"

namespace Apollo
{

	class KeyEvent : public Event
	{
	public:
		Key GetKey() const { return m_Key; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(Key key)
				: m_Key(key) {}

		Key m_Key;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(Key key)
				: KeyEvent(key) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << KeyToString(m_Key);
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(Key key)
				: KeyEvent(key) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << KeyToString(m_Key);
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
} // namespace Apollo

#endif /* end of include guard: KeyEvent_h */