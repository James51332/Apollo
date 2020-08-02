#include "CocoaContext.h"

#include <Cocoa/Cocoa.h>
#include <iostream>

#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

#include "CocoaInput.h"

////////////////////////////////////////////////////////////
///// CocoaView ////////////////////////////////////////////
////////////////////////////////////////////////////////////

@interface CocoaView : NSView
{
  Apollo::Window::WindowEventFn m_Callback;
  NSUInteger m_ModifierFlags;
}

- (instancetype) init;
- (void) setEventCallback: (const Apollo::Window::WindowEventFn &)callback;

@end

@implementation CocoaView 

- (instancetype) init
{
  if (self = [super initWithFrame: NSMakeRect(0.0, 0.0, 800.0, 600.0)])
  {
    m_ModifierFlags = 0;
    return self;
  }

  return NULL;
}

- (void) setEventCallback: (Apollo::Window::WindowEventFn)callback
{
  m_Callback = callback;
}

- (BOOL) acceptsFirstResponder
{
  return YES;
}

- (void) mouseDown:(NSEvent *) event
{
  Apollo::MouseButtonPressedEvent e(0);

  if (m_Callback)
    m_Callback(e);
}

- (void) mouseMoved:(NSEvent *) event
{
  NSPoint pos = [event locationInWindow];
  Apollo::MouseMovedEvent e(pos.x, pos.y);

  if (m_Callback)
    m_Callback(e);
}

- (void) mouseDragged:(NSEvent *) event
{
  [self mouseMoved: event];
}

- (void) mouseUp:(NSEvent *) event
{
   Apollo::MouseButtonReleasedEvent e(0);

  if (m_Callback)
    m_Callback(e);
}

- (void) rightMouseDown:(NSEvent *) event
{
  [super rightMouseDown: event];

  Apollo::MouseButtonPressedEvent e(0);

  if (m_Callback)
    m_Callback(e);
}

- (void) rightMouseDragged:(NSEvent *) event
{
  [self mouseMoved: event];
}

- (void) rightMouseUp:(NSEvent *) event
{
  Apollo::MouseButtonReleasedEvent e(0);

  if (m_Callback)
    m_Callback(e); 
}

- (void) otherMouseDown:(NSEvent *) event
{
  Apollo::MouseButtonPressedEvent e(0);

  if (m_Callback)
    m_Callback(e);
}

- (void) otherMouseDragged:(NSEvent *) event
{
  [self mouseMoved: event]; 
}

- (void) otherMouseUp:(NSEvent *) event
{
  Apollo::MouseButtonReleasedEvent e(0);

  if (m_Callback)
    m_Callback(e);
}

- (void) scrollWheel:(NSEvent *) event
{

}

- (void) keyDown:(NSEvent *) event
{
  Apollo::KeyPressedEvent e(Apollo::CocoaKeyCodeToApolloKeyCode([event keyCode]), 0);

  if (m_Callback)
    m_Callback(e);
}

- (void) keyUp:(NSEvent *) event
{
  Apollo::KeyReleasedEvent e(Apollo::CocoaKeyCodeToApolloKeyCode([event keyCode]));

  if (m_Callback)
    m_Callback(e);
}

- (void) flagsChanged:(NSEvent *) event
{
  NSUInteger flags = [event modifierFlags];
  Apollo::KeyPressedEvent press = Apollo::KeyPressedEvent(Apollo::KeyNone, 0);
    
  // Check for Key Presses
    
  if (Apollo::IsFlagDown(m_ModifierFlags, flags, NSEventModifierFlagCapsLock))
    press = Apollo::KeyPressedEvent(Apollo::KeyCapsLock, 0);
    
  else if (Apollo::IsFlagDown(m_ModifierFlags, flags, NSEventModifierFlagShift))
    press = Apollo::KeyPressedEvent(Apollo::KeyShift, 0);
    
  else if (Apollo::IsFlagDown(m_ModifierFlags, flags, NSEventModifierFlagControl))
    press = Apollo::KeyPressedEvent(Apollo::KeyControl, 0);
    
  else if (Apollo::IsFlagDown(m_ModifierFlags, flags, NSEventModifierFlagOption))
    press = Apollo::KeyPressedEvent(Apollo::KeyAlt, 0);
    
  else if (Apollo::IsFlagDown(m_ModifierFlags, flags, NSEventModifierFlagCommand))
    press = Apollo::KeyPressedEvent(Apollo::KeyCommand, 0);
    
  if (m_Callback && press.GetKeyCode() != Apollo::KeyNone)
  {
    m_Callback(press);
    m_ModifierFlags = flags;
    return;
  }
    
  // Check for Key Releases
  Apollo::KeyReleasedEvent release = Apollo::KeyReleasedEvent(Apollo::KeyNone);

  if (Apollo::IsFlagUp(m_ModifierFlags, flags, NSEventModifierFlagCapsLock))
    release = Apollo::KeyReleasedEvent(Apollo::KeyCapsLock);

  else if (Apollo::IsFlagUp(m_ModifierFlags, flags, NSEventModifierFlagShift))
    release = Apollo::KeyReleasedEvent(Apollo::KeyShift);

  else if (Apollo::IsFlagUp(m_ModifierFlags, flags, NSEventModifierFlagControl))
    release = Apollo::KeyReleasedEvent(Apollo::KeyControl);

  else if (Apollo::IsFlagUp(m_ModifierFlags, flags, NSEventModifierFlagOption))
    release = Apollo::KeyReleasedEvent(Apollo::KeyAlt);

  else if (Apollo::IsFlagUp(m_ModifierFlags, flags, NSEventModifierFlagCommand))
    release = Apollo::KeyReleasedEvent(Apollo::KeyCommand);
    
  if (m_Callback && release.GetKeyCode() != Apollo::KeyNone)
  {
    m_Callback(release);
    m_ModifierFlags = flags;
    return;
  }
}

@end

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
  // this warning  will only show up for xcode
    
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
