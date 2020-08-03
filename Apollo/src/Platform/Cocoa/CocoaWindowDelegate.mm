#define APOLLO_OBJC_PLUS_PLUS
#include "CocoaWindowDelegate.h"

#include "Events/ApplicationEvent.h"

@implementation CocoaWindowDelegate

- (instancetype) init
{
  if (self = [super init])
  {
    return self;
  }

  return NULL;
}

- (void) setEventCallback: (const Apollo::Window::WindowEventFn &) callback
{
  m_Callback = callback;
}

- (BOOL) windowShouldClose:(NSWindow *)window 
{
  Apollo::WindowCloseEvent e;

  if (m_Callback)
    m_Callback(e);
  
  return NO;
}

- (NSSize)windowWillResize:(NSWindow *)sender toSize:(NSSize)frameSize
{
  NSSize contentSize = [sender contentRectForFrameRect: [sender frame]].size;
  Apollo::WindowResizeEvent e(contentSize.width, contentSize.height);

  if (m_Callback)
    m_Callback(e);

  return frameSize;
}


@end
