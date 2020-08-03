#ifndef CocoaWindowDelegate_h
#define CocoaWindowDelegate_h

#ifdef APOLLO_OBJC_PLUS_PLUS

#include "Core/Window.h"

#include <Cocoa/Cocoa.h>

@interface CocoaWindowDelegate : NSObject <NSWindowDelegate>
{
  Apollo::Window::WindowEventFn m_Callback;
}

- (instancetype)init;
- (void)setEventCallback:(const Apollo::Window::WindowEventFn &)callback;

@end

#endif

#endif /* end of include guard: CocoaWindowDelegate_h */