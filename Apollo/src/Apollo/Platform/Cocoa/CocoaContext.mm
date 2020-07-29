#include "CocoaContext.h"

#include <Cocoa/Cocoa.h>

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
  //NSView doesn't work properly if we don't init with a frame;
  m_View = [[NSView alloc] initWithFrame:NSMakeRect(0.0, 0.0, 800.0, 600.0)];

  NSOpenGLPixelFormatAttribute attributes[] = {
    NSOpenGLPFADepthSize, 32,
    NSOpenGLPFADoubleBuffer,
    NSOpenGLPFAOpenGLProfile, NSOpenGLProfileVersion4_1Core, 
    0
  };

  NSOpenGLPixelFormat *pixelFormat = [[NSOpenGLPixelFormat alloc] initWithAttributes: attributes];

  m_Context = [[NSOpenGLContext alloc] initWithFormat: pixelFormat
                                         shareContext: nil];


  // Supress setView Deprecation. We can
  // use clang specific pragmas because
  // this warning  will only show up for xcode
    
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
  [(NSOpenGLContext *)m_Context setView: (NSView *)m_View];
#pragma clang diagnostic pop

  [(NSOpenGLContext *)m_Context makeCurrentContext];
}

CocoaOpenGLContext::~CocoaOpenGLContext() 
{

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
  [(NSOpenGLContext *)m_Context setView: nil];
#pragma clang diagnostic pop
    
  [(NSView *)m_View release];
  m_View = nullptr;

  [(NSOpenGLContext *)m_Context release];
  m_Context = nullptr;
}

void CocoaOpenGLContext::Update() 
{
  [(NSOpenGLContext *)m_Context flushBuffer];
}

void CocoaOpenGLContext::SetWindow(void *window) 
{
  NSSize size = [(NSWindow *)window contentRectForFrameRect: [(NSWindow *)window frame]].size;
  [(NSView *)m_View setFrameSize: size];

  [(NSWindow *)window setContentView: (NSView *)m_View];
}

} // namespace Apollo
