#ifndef CocoaInput_h
#define CocoaInput_h

#include "Application/KeyCodes.h"

namespace Apollo
{

  static Key CocoaKeyCodeToApolloKey(int keyCode)
  {
    switch (keyCode)
    {
    case 0x00:
      return Key::A;
      break;
    case 0x0b:
      return Key::B;
      break;
    case 0x08:
      return Key::C;
      break;
    case 0x02:
      return Key::D;
      break;
    case 0x0e:
      return Key::E;
      break;
    case 0x03:
      return Key::F;
      break;
    case 0x05:
      return Key::G;
      break;
    case 0x04:
      return Key::H;
      break;
    case 0x22:
      return Key::I;
      break;
    case 0x26:
      return Key::J;
      break;
    case 0x28:
      return Key::K;
      break;
    case 0x25:
      return Key::L;
      break;
    case 0x2e:
      return Key::M;
      break;
    case 0x2d:
      return Key::N;
      break;
    case 0x1f:
      return Key::O;
      break;
    // case 0x00:
    //   return Key::P;
    //   break;
    // case 0x00:
    //   return Key::Q;
    //   break;
    // case 0x00:
    //   return Key::R;
    //   break;
    // case 0x00:
    //   return Key::S;
    //   break;
    // case 0x00:
    //   return Key::T;
    //   break;
    // case 0x00:
    //   return Key::U;
    //   break;
    // case 0x00:
    //   return Key::V;
    //   break;
    // case 0x00:
    //   return Key::W;
    //   break;
    // case 0x00:
    //   return Key::X;
    //   break;
    // case 0x00:
    //   return Key::Y;
    //   break;
    // case 0x00:
    //   return Key::Z;
    //   break;
    // case 0x00:
    //   return Key::SPACE;
    //   break;
    // case 0x00:
    //   return Key::ESC;
    //   break;
    // case 0x00:
    //   return Key::LEFT;
    //   break;
    // case 0x00:
    //   return Key::RIGHT;
    //   break;
    // case 0x00:
    //   return Key::UP;
    //   break;
    // case 0x00:
    //   return Key::DOWN;
    //   break;
    // case 0x00:
    //   return Key::ALT;
    //   break;
    // case 0x00:
    //   return Key::CONTROL;
    //   break;
    // case 0x00:
    //   return Key::FUNCTION;
    //   break;
    // case 0x00:
    //   return Key::LEFT_SHIFT;
    //   break;
    // case 0x00:
    //   return Key::RIGHT_SHIFT;
    //   break;
    // case 0x00:
    //   return Key::CAPS_LOCK;
    //   break;
    // case 0x00:
    //   return Key::TAB;
    //   break;
    // case 0x00:
    //   return Key::GRAVE;
    //   break;
    // case 0x00:
    //   return Key::MINUS;
    //   break;
    // case 0x00:
    //   return Key::PLUS;
    //   break;
    // case 0x00:
    //   return Key::SLASH;
    //   break;
    // case 0x00:
    //   return Key::BACKSLASH;
    //   break;
    // case 0x00:
    //   return Key::BACKSPACE;
    //   break;
    // case 0x00:
    //   return Key::ENTER;
    //   break;
    // case 0x00:
    //   return Key::APOSTROPHE;
    //   break;
    // case 0x00:
    //   return Key::SEMICOLON;
    //   break;
    // case 0x00:
    //   return Key::COMMA;
    //   break;
    // case 0x00:
    //   return Key::PERIOD;
    //   break;
    // case 0x00:
    //   return Key::F1;
    //   break;
    // case 0x00:
    //   return Key::F2;
    //   break;
    // case 0x00:
    //   return Key::F3;
    //   break;
    // case 0x00:
    //   return Key::F4;
    //   break;
    // case 0x00:
    //   return Key::F5;
    //   break;
    // case 0x00:
    //   return Key::F6;
    //   break;
    // case 0x00:
    //   return Key::F7;
    //   break;
    // case 0x00:
    //   return Key::F8;
    //   break;
    // case 0x00:
    //   return Key::F9;
    //   break;
    // case 0x00:
    //   return Key::F10;
    //   break;
    // case 0x00:
    //   return Key::F11;
    //   break;
    // case 0x00:
    //   return Key::F12;
    //   break;
    default:
      return Key::A;
      break;
    }
  }

} // namespace Apollo

#endif /* end of include guard: CocoaInput_h */