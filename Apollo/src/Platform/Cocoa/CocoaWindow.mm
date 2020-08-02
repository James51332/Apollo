#include "CocoaWindow.h"

#include <Cocoa/Cocoa.h>

#include "CocoaContext.h"

@interface WindowDelegate : NSObject <NSWindowDelegate> {
  bool *open;
}
- (id) init:(bool *)handle;
@end

@implementation WindowDelegate
- (id) init:(bool *)handle {
 open = handle;
 return self;
}

- (BOOL) windowShouldClose:(NSWindow *)window {
  (*open) = false;
  return YES;
}
@end

namespace Apollo {

CocoaWindow::CocoaWindow(const WindowDescription &desc) {

  NSRect frame = NSMakeRect(0.0, 0.0, desc.Width, desc.Height);

  NSUInteger styleMask = NSWindowStyleMaskClosable
                       | NSWindowStyleMaskTitled
                       | NSWindowStyleMaskMiniaturizable;

  if (desc.Resizable)
    styleMask |= NSWindowStyleMaskResizable;

  m_Object = [[NSWindow alloc] initWithContentRect: frame 
                                         styleMask: styleMask
                                           backing: NSBackingStoreBuffered
                                             defer: NO];

  [(NSWindow *)m_Object center];
  [(NSWindow *)m_Object setTitle: @(desc.Title.c_str())];
  
  m_Delegate = [[WindowDelegate alloc] init: &m_Open];
  [(NSWindow *)m_Object setDelegate: (id<NSWindowDelegate>)m_Delegate];
}

CocoaWindow::~CocoaWindow() {
  ((CocoaContext *)m_Context)->SetWindow(nullptr);
  delete m_Context;
  m_Context = nullptr;

  [(NSWindow *)m_Object release];
  m_Object = nullptr;
}

void CocoaWindow::Show() 
{
  [(NSWindow *)m_Object makeKeyAndOrderFront: nil];
  [(NSWindow *)m_Object makeMainWindow];
  m_Open = true;  
}

void CocoaWindow::Update() 
{
  m_Context->Update();
}

void CocoaWindow::SetEventCallback(const Window::WindowEventFn &callback)
{
  m_Callback = callback;
  
  if (m_Context != nullptr)
    ((CocoaContext *)m_Context)->SetEventCallback(callback);
}

void CocoaWindow::SetDesc(const WindowDescription &desc) {
  int titlebar = [(NSWindow *)m_Object frame].size.height - GetHeight();

  [(NSWindow *)m_Object setFrame: NSMakeRect(0.0, 0.0, desc.Width, desc.Height + titlebar)
                         display: NO];
                      
  [(NSWindow *)m_Object center];
  [(NSWindow *)m_Object setTitle: @(desc.Title.c_str())];
}


void CocoaWindow::SetContext(RenderingContext *context) 
{
  m_Context = context;

  ((CocoaContext *) context)->SetWindow(m_Object);
}

int CocoaWindow::GetWidth() 
{
  return [(NSWindow *)m_Object contentRectForFrameRect: [(NSWindow *)m_Object frame]].size.width;
}

int CocoaWindow::GetHeight() 
{
  return [(NSWindow *)m_Object contentRectForFrameRect: [(NSWindow *)m_Object frame]].size.height;
}

} // namespace Apollo