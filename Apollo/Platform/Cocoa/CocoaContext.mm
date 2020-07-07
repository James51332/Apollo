#include "CocoaContext.h"
#include "CocoaInput.h"

#include "Application/Window.h"
#include "Application/Events/KeyEvent.h"
#include "Application/Events/Event.h"
#include "Application/Events/ApplicationEvent.h"

#include <Cocoa/Cocoa.h>

@interface ApolloView : NSView
{
  Apollo::Window::EventCallbackFn callback;
}

- (void) setCallback:(Apollo::Window::EventCallbackFn) handle;

@end

@implementation ApolloView

- (void) setCallback:(Apollo::Window::EventCallbackFn) handle {
  callback = handle;
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