#ifndef KeyEvent_h
#define KeyEvent_h

#include "Event.h"
#include "Application/KeyCodes.h"

#include <sstream>

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
		KeyPressedEvent(Key key, int repeatCount)
				: KeyEvent(key), m_RepeatCount(repeatCount) {}

		int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << KeyToString(m_Key) << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(Key key)
				: KeyEvent(key) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
} // namespace Apollo

#endif /* end of include guard: KeyEvent_h */