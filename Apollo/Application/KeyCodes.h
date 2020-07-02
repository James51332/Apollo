#ifndef KeyCodes_h
#define KeyCodes_h

namespace Apollo
{

  enum class Key
  {
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z, // 26 Letters

    SPACE,
    ESC,
    LEFT,
    RIGHT,
    UP,
    DOWN,
    ALT,
    CONTROL,
    FUNCTION,
    LEFT_SHIFT,
    RIGHT_SHIFT,
    CAPS_LOCK,
    TAB,
    GRAVE,
    MINUS,
    PLUS,
    SLASH,
    BACKSLASH,
    BACKSPACE,
    ENTER,
    APOSTROPHE,
    SEMICOLON,
    COMMA,
    PERIOD, // 24 Misc

    F1,
    F2,
    F3,
    F4,
    F5,
    F6,
    F7,
    F8,
    F9,
    F10,
    F11,
    F12 // 12 Functions
  };

  static std::string KeyToString(Key key)
  {
    switch (key)
    {
    case Key::A:
      return "A";
      break;
    case Key::B:
      return "B";
      break;
    case Key::C:
      return "C";
      break;
    case Key::D:
      return "D";
      break;
    case Key::E:
      return "E";
      break;
    case Key::F:
      return "F";
      break;
    case Key::G:
      return "G";
      break;
    case Key::H:
      return "H";
      break;
    case Key::I:
      return "I";
      break;
    case Key::J:
      return "J";
      break;
    case Key::K:
      return "K";
      break;
    case Key::L:
      return "L";
      break;
    case Key::M:
      return "M";
      break;
    case Key::N:
      return "N";
      break;
    case Key::O:
      return "O";
      break;
    case Key::P:
      return "P";
      break;
    case Key::Q:
      return "Q";
      break;
    case Key::R:
      return "R";
      break;
    case Key::S:
      return "S";
      break;
    case Key::T:
      return "T";
      break;
    case Key::U:
      return "U";
      break;
    case Key::V:
      return "V";
      break;
    case Key::W:
      return "W";
      break;
    case Key::X:
      return "X";
      break;
    case Key::Y:
      return "Y";
      break;
    case Key::Z:
      return "Z";
      break;
    case Key::SPACE:
      return "Space";
      break;
    case Key::ESC:
      return "Escape";
      break;
    case Key::LEFT:
      return "Left";
      break;
    case Key::RIGHT:
      return "Right";
      break;
    case Key::UP:
      return "Up";
      break;
    case Key::DOWN:
      return "Down";
      break;
    case Key::ALT:
      return "Alt";
      break;
    case Key::CONTROL:
      return "Control";
      break;
    case Key::FUNCTION:
      return "Function";
      break;
    case Key::LEFT_SHIFT:
      return "Left Shift";
      break;
    case Key::RIGHT_SHIFT:
      return "Right Shift";
      break;
    case Key::CAPS_LOCK:
      return "Caps Lock";
      break;
    case Key::TAB:
      return "Tab";
      break;
    case Key::GRAVE:
      return "Grave";
      break;
    case Key::MINUS:
      return "-";
      break;
    case Key::PLUS:
      return "+";
      break;
    case Key::SLASH:
      return "/";
      break;
    case Key::BACKSLASH:
      return "\\";
      break;
    case Key::BACKSPACE:
      return "Backspace";
      break;
    case Key::ENTER:
      return "Enter";
      break;
    case Key::APOSTROPHE:
      return "'";
      break;
    case Key::SEMICOLON:
      return ";";
      break;
    case Key::COMMA:
      return ",";
      break;
    case Key::PERIOD:
      return ".";
      break;
    case Key::F1:
      return "F1";
      break;
    case Key::F2:
      return "F2";
      break;
    case Key::F3:
      return "F3";
      break;
    case Key::F4:
      return "F4";
      break;
    case Key::F5:
      return "F5";
      break;
    case Key::F6:
      return "G6";
      break;
    case Key::F7:
      return "F7";
      break;
    case Key::F8:
      return "F8";
      break;
    case Key::F9:
      return "F9";
      break;
    case Key::F10:
      return "F10";
      break;
    case Key::F11:
      return "F11";
      break;
    case Key::F12:
      return "F12";
      break;
    }
  }

} // namespace Apollo
#endif /* end of include guard: KeyCodes_h  */