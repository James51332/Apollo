#include "CocoaContext.h"
#include "CocoaInput.h"

#include "Application/Window.h"
#include "Application/Events/KeyEvent.h"
#include "Application/Events/Event.h"
#include "Application/Events/ApplicationEvent.h"

#include "Platform/OpenGL/OpenGLLoader.h"

#include <Cocoa/Cocoa.h>
#include <iostream>

@interface ApolloView : NSView
{
  std::function<void(Apollo::Event &)> callback;
}

- (void) setCallback:(std::function<void(Apollo::Event &)>) handle;

@end

@implementation ApolloView

- (void) setCallback:(std::function<void(Apollo::Event &)>) handle {
  callback = handle;
}

- (void) keyDown:(NSEvent *)event
{
  std::cout << [event keyCode] << std::endl;

  if (callback != nullptr)
  {
    Apollo::KeyPressedEvent e(Apollo::CocoaKeyCodeToApolloKey([event keyCode]), 0);
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

- (BOOL)wantsUpdateLayer
{
    return YES;
}

- (void)updateLayer
{
  Apollo::AppRenderEvent e = {};
}

- (void)drawRect:(NSRect)dirtyRect
{
  Apollo::AppRenderEvent e = {};
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

////////////////////////////////////////////////////////////
///// CocoaOpenGLContext ///////////////////////////////////
////////////////////////////////////////////////////////////

CocoaOpenGLContext::CocoaOpenGLContext() 
{
  //ApolloView doesn't work properly if we don't init with a frame;
  m_View = [[ApolloView alloc] initWithFrame: NSMakeRect(0.0, 0.0, 800.0, 600.0)];

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
  [(ApolloView *)m_View setNeedsDisplay:YES];
}

void CocoaOpenGLContext::SetWindow(void *window) 
{
  NSSize size = [(NSWindow *)window contentRectForFrameRect: [(NSWindow *)window frame]].size;
  [(ApolloView *)m_View setFrameSize: size];

  [(NSWindow *)window setContentView: (ApolloView *)m_View];
  [(NSWindow *)window makeFirstResponder: (ApolloView *)m_View];
}

void CocoaOpenGLContext::SetCallback(const Window::EventCallbackFn &callback)
{
  [(ApolloView *)m_View setCallback: callback];
}

} // namespace Apollo