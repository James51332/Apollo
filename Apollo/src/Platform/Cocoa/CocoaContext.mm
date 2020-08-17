#define APOLLO_OBJC_PLUS_PLUS
#include "CocoaContext.h"
#include "CocoaView.h"

namespace Apollo {

////////////////////////////////////////////////////////////
///// CocoaContext /////////////////////////////////////////
////////////////////////////////////////////////////////////

CocoaContext *CocoaContext::Create(RenderingApi::Api api) 
{
  switch (api) {
    case RenderingApi::Api::OpenGL: return new CocoaOpenGLContext(); break;
    case RenderingApi::Api::None: break;
  }
    
  return nullptr;
}

CocoaContext::~CocoaContext() 
{

}

////////////////////////////////////////////////////////////
///// CocoaOpenGLContext ///////////////////////////////////
////////////////////////////////////////////////////////////

CocoaOpenGLContext::CocoaOpenGLContext() 
{
  m_View = [[CocoaView alloc] init];

  NSOpenGLPixelFormatAttribute attributes[] = {
    NSOpenGLPFADepthSize, 32,
    NSOpenGLPFADoubleBuffer,
    NSOpenGLPFAOpenGLProfile, NSOpenGLProfileVersion4_1Core, 
    0
  };

  NSOpenGLPixelFormat *pixelFormat = [[NSOpenGLPixelFormat alloc] initWithAttributes: attributes];

  m_Context = [[NSOpenGLContext alloc] initWithFormat: pixelFormat
                                         shareContext: nil];


  // Suppress setView Deprecation. We can
  // use clang specific pragmas because
  // this warning will only show up for xcode
    
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
  [(NSOpenGLContext *)m_Context setView: (CocoaView *)m_View];
#pragma clang diagnostic pop

  [(NSOpenGLContext *)m_Context makeCurrentContext];
}

CocoaOpenGLContext::~CocoaOpenGLContext() 
{

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
  [(NSOpenGLContext *)m_Context setView: nil];
#pragma clang diagnostic pop
    
  [(CocoaView *)m_View release];
  m_View = nullptr;

  [(NSOpenGLContext *)m_Context release];
  m_Context = nullptr;
}

void CocoaOpenGLContext::Update() 
{
  [(NSOpenGLContext *)m_Context flushBuffer];
}

void CocoaOpenGLContext::SetEventCallback(const Window::WindowEventFn &callback)
{
  m_Callback = callback;
  [(CocoaView *)m_View setEventCallback: callback];
}

void CocoaOpenGLContext::SetWindow(void *window) 
{
  NSSize size = [(NSWindow *)window contentRectForFrameRect: [(NSWindow *)window frame]].size;
  [(CocoaView *)m_View setFrameSize: size];

  [(NSWindow *)window setContentView: (CocoaView *)m_View];
  [(NSWindow *)window makeFirstResponder: (CocoaView *)m_View];
}

} // namespace Apollo
