#ifndef CocoaView_h
#define CocoaView_h

#ifdef APOLLO_OBJC_PLUS_PLUS

#include "Core/KeyCodes.h"
#include "Core/MouseCodes.h"
#include "Core/Window.h"

#include <Cocoa/Cocoa.h>

@interface CocoaView : NSView
{
  Apollo::Window::WindowEventFn m_Callback;

  NSUInteger m_ModifierFlags;

  Apollo::KeyCode m_KeyCodes[128];
  Apollo::MouseCode m_MouseCodes[16];
}

- (instancetype)init;
- (void)setEventCallback:(const Apollo::Window::WindowEventFn &)callback;

@end

#endif

#endif /* end of include guard: CocoaView_h */
