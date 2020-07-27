#include "CocoaContext.h"
#include "CocoaInput.h"

#include "Application/Window.h"
#include "Events/KeyEvent.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Events/MouseEvent.h"

#include <Cocoa/Cocoa.h>
#include <iostream>

@interface ApolloView : NSView
{
  Apollo::Window::EventCallbackFn callback;
}

- (void) setCallback:(Apollo::Window::EventCallbackFn) handle;

@end

@implementation ApolloView

- (void) setCallback:(Apollo::Window::EventCallbackFn) handle 
{
  callback = handle;
}

- (void) mouseDown:(NSEvent *)event
{
  if (callback != nullptr) 
  {
    Apollo::MouseButtonPressedEvent e(Apollo::Mouse::Left);
    callback(e);
  }
}

- (void) mouseUp:(NSEvent *)event
{
  if (callback != nullptr) 
  {
    Apollo::MouseButtonReleasedEvent e(Apollo::Mouse::Left);
    callback(e);
  }
}

- (void) mouseMoved:(NSEvent *)event
{
  if (callback != nullptr)
  {
    Apollo::MouseMovedEvent e([event locationInWindow].x, [event locationInWindow].y);
    callback(e);
  }
}

- (void) rightMouseDown:(NSEvent *)event
{
  [super rightMouseDown:event];

  if (callback != nullptr)
  {
    Apollo::MouseButtonPressedEvent e(Apollo::Mouse::Right);
    callback(e);
  }
}

- (void) rightMightDragged:(NSEvent *)event
{
  [self mouseMoved: event];
}

- (void) rightMouseUp:(NSEvent *)event
{
  if (callback != nullptr)
  {
    Apollo::MouseButtonReleasedEvent e(Apollo::Mouse::Right);
    callback(e);
  }
}

// TODO: Implement Other Mouse Buttons
// - (void) otherMouseDown:(NSEvent *)event
// {
//   if (callback != nullptr)
//   {
//   }
// }

// - (void) outherMouseDragged:(NSEvent *)event
// {
//   if (callback != nullptr)
//   {
//   }
// }

// - (void) otherMouseUp:(NSEvent *)event
// {
//   if (callback != nullptr)
//   {
//   }
// }

// TODO: Implement Scroll Wheel
- (void) scrollWheel:(NSEvent *)event
{
  if (callback != nullptr)
  {
  }
}

- (void) keyDown:(NSEvent *)event
{
  if (callback != nullptr)
  {
    Apollo::KeyPressedEvent e(Apollo::CocoaKeyCodeToApolloKey([event keyCode]));
    callback(e);
  }
}

- (void) keyUp:(NSEvent *)event
{
  if (callback != nullptr)
  {
    Apollo::KeyReleasedEvent e(Apollo::CocoaKeyCodeToApolloKey([event keyCode]));
    callback(e);
  }
}

// TODO: Store Flags and Detect Changes
- (void) flagsChanged:(NSEvent *)event
{
  if (callback != nullptr)
  {

  }
}

- (BOOL)canBecomeKeyView
{
    return YES;
}

- (BOOL)acceptsFirstResponder
{
    return YES;
}

@end

namespace Apollo {

////////////////////////////////////////////////////////////
///// CocoaContext /////////////////////////////////////////
////////////////////////////////////////////////////////////

CocoaContext *CocoaContext::Create(RenderingApi::Api api) 
{
  switch (api) {
    case RenderingApi::Api::None: return nullptr; break;
    case RenderingApi::Api::OpenGL: return new CocoaOpenGLContext(); break;
    default: return nullptr;
  }
}

CocoaContext::~CocoaContext() 
{

}

void CocoaContext::SetCallback(const Window::EventCallbackFn &callback)
{
  [(ApolloView *)m_View setCallback: callback];
}

////////////////////////////////////////////////////////////
///// CocoaOpenGLContext ///////////////////////////////////
////////////////////////////////////////////////////////////

CocoaOpenGLContext::CocoaOpenGLContext() 
{
  //ApolloView doesn't work properly if we don't init with a frame;
  m_View = [[ApolloView alloc] initWithFrame: NSMakeRect(0.0, 0.0, 1.0, 1.0)];

  NSOpenGLPixelFormatAttribute attributes[] = {
    NSOpenGLPFADepthSize, 32,
    NSOpenGLPFADoubleBuffer,
    NSOpenGLPFAOpenGLProfile, NSOpenGLProfileVersion4_1Core, 
    0
  };

  NSOpenGLPixelFormat *pixelFormat = [[NSOpenGLPixelFormat alloc] initWithAttributes: attributes];

  m_Context = [[NSOpenGLContext alloc] initWithFormat: pixelFormat
                                         shareContext: nil];

  [(NSOpenGLContext *)m_Context setView: (ApolloView *)m_View];
  [(NSOpenGLContext *)m_Context makeCurrentContext];
}

CocoaOpenGLContext::~CocoaOpenGLContext() 
{
  [(NSOpenGLContext *)m_Context setView: nil];
  [(ApolloView *)m_View release];
  m_View = nullptr;

  [(NSOpenGLContext *)m_Context release];
  m_Context = nullptr;
}

void CocoaOpenGLContext::Update() 
{
  [(NSOpenGLContext *)m_Context flushBuffer];
  [(NSOpenGLContext *)m_Context update];
  [(ApolloView *)m_View setNeedsDisplay: YES];
}

void CocoaOpenGLContext::SetWindow(void *window) 
{
  NSSize size = [(NSWindow *)window contentRectForFrameRect: [(NSWindow *)window frame]].size;
  [(ApolloView *)m_View setFrameSize: size];
  [(NSOpenGLContext *)m_Context update];

  [(NSWindow *)window setContentView: (ApolloView *)m_View];
  [(NSWindow *)window makeFirstResponder: (ApolloView *)m_View];
}

} // namespace Apollo