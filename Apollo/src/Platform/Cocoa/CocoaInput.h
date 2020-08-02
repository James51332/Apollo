#ifndef CocoaInput_h
#define CocoaInput_h

#include <Cocoa/Cocoa.h>

#include "Core/KeyCodes.h"

namespace Apollo
{

  static KeyCode CocoaKeyCodeToApolloKeyCode(int keyCode)
  {
    switch (keyCode)
    {
    case 0:
      return KeyA;
    case 11:
      return KeyB;
    case 8:
      return KeyC;
    case 2:
      return KeyD;
    case 14:
      return KeyE;
    case 3:
      return KeyF;
    case 5:
      return KeyG;
    case 4:
      return KeyH;
    case 34:
      return KeyI;
    case 38:
      return KeyJ;
    case 40:
      return KeyK;
    case 37:
      return KeyL;
    case 46:
      return KeyM;
    case 45:
      return KeyN;
    case 31:
      return KeyO;
    case 35:
      return KeyP;
    case 12:
      return KeyQ;
    case 15:
      return KeyR;
    case 1:
      return KeyS;
    case 17:
      return KeyT;
    case 32:
      return KeyU;
    case 9:
      return KeyV;
    case 13:
      return KeyW;
    case 7:
      return KeyX;
    case 16:
      return KeyY;
    case 6:
      return KeyZ;
    case 53:
      return KeyEscape;
    case 50:
      return KeyGrave;
    case 48:
      return KeyTab;
    case 123:
      return KeyLeft;
    case 126:
      return KeyUp;
    case 125:
      return KeyDown;
    case 124:
      return KeyRight;
    case 42:
      return KeyBackslash;
    case 51:
      return KeyBackspace;
    case 30:
      return KeyRightBracket;
    case 33:
      return KeyLeftBracket;
    case 27:
      return KeyDash;
    case 24:
      return KeyEquals;
    case 122:
      return KeyF1;
    case 120:
      return KeyF2;
    case 99:
      return KeyF3;
    case 118:
      return KeyF4;
    case 96:
      return KeyF5;
    case 97:
      return KeyF6;
    case 98:
      return KeyF7;
    case 100:
      return KeyF8;
    case 101:
      return KeyF9;
    case 109:
      return KeyF10;
    case 103:
      return KeyF11;
    case 111:
      return KeyF12;
    }
      
      return KeyA;
  }

  static bool IsFlagDown(NSUInteger oldFlags, NSUInteger newFlags, NSUInteger flag)
  {
    return (!(oldFlags & flag) && (newFlags & flag));
  }

  static bool IsFlagUp(NSUInteger oldFlags, NSUInteger newFlags, NSUInteger flag)
  {
    return ((oldFlags & flag) && !(newFlags & flag));
  }

} // namespace Apollo

#endif /* end of include guard: CocoaInput_h */
