#ifndef Input_h
#define Input_h

#include "Game.h"
#include "Application.h"

#include "KeyCodes.h"
#include "MouseCodes.h"

#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

namespace Apollo
{

  class Input
  {
    friend class Game;

  public:
    static bool IsKeyPressed(KeyCode key);
    static bool IsKeyDown(KeyCode key);
    static bool IsKeyReleased(KeyCode key);

    static bool IsMousePressed(MouseCode button);
    static bool IsMouseDown(MouseCode button);
    static bool IsMouseReleased(MouseCode button);

  private:
    static void Initialize();
    static void Deinitialize();
      
    static bool OnEvent(Event &event);
    static Input *s_Instance;

    Input();

    bool m_KeyState[128];
    bool m_LastKeyState[128];

    bool m_MouseState[16];
    bool m_LastMouseState[16];
  };

} // namespace Apollo

#endif /* end of include guard: Input_h */
