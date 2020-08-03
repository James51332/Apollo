#ifndef CocoaInput_h
#define CocoaInput_h

#ifdef APOLLO_OBJC_PLUS_PLUS

#include "Core/KeyCodes.h"

namespace Apollo
{
  static void CocoaInitKeyCodes(Apollo::KeyCode *keyCodes)
  {
    keyCodes[0] = KeyA;
    keyCodes[11] = KeyB;
    keyCodes[8] = KeyC;
    keyCodes[2] = KeyD;
    keyCodes[14] = KeyE;
    keyCodes[3] = KeyF;
    keyCodes[5] = KeyG;
    keyCodes[4] = KeyH;
    keyCodes[34] = KeyI;
    keyCodes[38] = KeyJ;
    keyCodes[40] = KeyK;
    keyCodes[37] = KeyL;
    keyCodes[46] = KeyM;
    keyCodes[45] = KeyN;
    keyCodes[31] = KeyO;
    keyCodes[35] = KeyP;
    keyCodes[12] = KeyQ;
    keyCodes[15] = KeyR;
    keyCodes[1] = KeyS;
    keyCodes[17] = KeyT;
    keyCodes[32] = KeyU;
    keyCodes[9] = KeyV;
    keyCodes[13] = KeyW;
    keyCodes[7] = KeyX;
    keyCodes[16] = KeyY;
    keyCodes[6] = KeyZ;
    keyCodes[53] = KeyEscape;
    keyCodes[50] = KeyGrave;
    keyCodes[48] = KeyTab;
    keyCodes[123] = KeyLeft;
    keyCodes[126] = KeyUp;
    keyCodes[125] = KeyDown;
    keyCodes[124] = KeyRight;
    keyCodes[42] = KeyBackslash;
    keyCodes[51] = KeyBackspace;
    keyCodes[30] = KeyRightBracket;
    keyCodes[33] = KeyLeftBracket;
    keyCodes[27] = KeyDash;
    keyCodes[24] = KeyEquals;
    keyCodes[122] = KeyF1;
    keyCodes[120] = KeyF2;
    keyCodes[99] = KeyF3;
    keyCodes[118] = KeyF4;
    keyCodes[96] = KeyF5;
    keyCodes[97] = KeyF6;
    keyCodes[98] = KeyF7;
    keyCodes[100] = KeyF8;
    keyCodes[101] = KeyF9;
    keyCodes[109] = KeyF10;
    keyCodes[103] = KeyF11;
    keyCodes[111] = KeyF12;
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

#endif

#endif /* end of include guard: CocoaInput_h */
