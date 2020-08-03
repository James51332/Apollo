#include "Input.h"

#include <cstdlib>
#include <cstdarg>
#include <iostream>

namespace Apollo
{
  Input *Input::s_Instance = new Input();

  bool Input::IsKeyPressed(KeyCode key)
  {
    return s_Instance->m_KeyState[key] && !s_Instance->m_LastKeyState[key];
  }

  bool Input::IsKeyDown(KeyCode key)
  {
    return s_Instance->m_KeyState[key];
  }

  bool Input::IsKeyReleased(KeyCode key)
  {
    return !s_Instance->m_KeyState[key] && s_Instance->m_LastKeyState[key];
  }

  bool Input::IsMousePressed(MouseCode button)
  {
    return s_Instance->m_MouseState[button] && !s_Instance->m_LastKeyState[button];
  }

  bool Input::IsMouseDown(MouseCode button)
  {
    return s_Instance->m_MouseState[button];
  }

  bool Input::IsMouseReleased(MouseCode button)
  {
    return !s_Instance->m_MouseState[button] && s_Instance->m_LastKeyState[button];
  }

  void Input::Initialize()
  {
  }

  void Input::Deinitialize()
  {
    delete s_Instance;
  }

  bool Input::OnEvent(Event &event)
  {
    memcpy(s_Instance->m_LastKeyState, s_Instance->m_KeyState, sizeof(s_Instance->m_LastKeyState));
    memcpy(s_Instance->m_LastMouseState, s_Instance->m_MouseState, sizeof(s_Instance->m_LastMouseState));
      
    if (event.GetEventType() == EventType::KeyPressed)
    {
      KeyPressedEvent e = static_cast<KeyPressedEvent &>(event);
      s_Instance->m_KeyState[e.GetKeyCode()] = true;
    }

    if (event.GetEventType() == EventType::KeyReleased)
    {
      KeyReleasedEvent e = static_cast<KeyReleasedEvent &>(event);
      s_Instance->m_KeyState[e.GetKeyCode()] = false;
    }

    return false;
  }

  Input::Input()
  {
    for (int i = 0; i < 128; i++)
    {
      m_KeyState[i] = false;
      m_LastKeyState[i] = false;
    }

    for (int i = 0; i < 16; i++)
    {
      m_MouseState[i] = false;
      m_LastMouseState[i] = false;
    }
  }

} // namespace Apollo
