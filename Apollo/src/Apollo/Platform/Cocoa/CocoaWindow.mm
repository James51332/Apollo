#include "CocoaWindow.h"
#include "CocoaContext.h"

#include "Events/ApplicationEvent.h"

#include <Cocoa/Cocoa.h>


@interface WindowDelegate : NSObject <NSWindowDelegate> {
  bool *open;
  Apollo::Window::EventCallbackFn callback;
}
- (id) init:(bool *)handle;
- (void) setEventCallback:(Apollo::Window::EventCallbackFn)handle;
@end

@implementation WindowDelegate
- (id) init:(bool *)handle {
 open = handle;
 return self;
}

- (void) setEventCallback:(Apollo::Window::EventCallbackFn)handle
{
  callback = handle;
}

- (BOOL) windowShouldClose:(NSWindow *)window 
{
  if (open != nullptr)
    (*open) = false;
  
  if (callback != nullptr)
  {
    Apollo::WindowCloseEvent e;
    callback(e);
  }
  
  return YES;
}

- (NSSize) windowWillResize:(NSWindow *)window toSize:(NSSize)size
{
  if (callback != nullptr)
  {  
    Apollo::WindowResizeEvent e(size.width, size.height);
    callback(e);
  }

  return size;
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

  [(NSWindow *)m_Object setAcceptsMouseMovedEvents: YES];
  
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

void CocoaWindow::Update() {
  m_Context->Update();
}

void CocoaWindow::SetContext(RenderingContext *context) {
  m_Context = context;
  ((CocoaContext *) context)->SetWindow(m_Object);
}

int CocoaWindow::GetWidth() {
  return [(NSWindow *)m_Object contentRectForFrameRect: [(NSWindow *)m_Object frame]].size.width;
}

int CocoaWindow::GetHeight() {
  return [(NSWindow *)m_Object contentRectForFrameRect: [(NSWindow *)m_Object frame]].size.height;
}

void CocoaWindow::SetDesc(const WindowDescription &desc) {
  int titlebar = [(NSWindow *)m_Object frame].size.height - GetHeight();

  [(NSWindow *)m_Object setFrame: NSMakeRect(0.0, 0.0, desc.Width, desc.Height + titlebar)
                         display: NO];
                      
  [(NSWindow *)m_Object center];
  [(NSWindow *)m_Object setTitle: @(desc.Title.c_str())];
}

void CocoaWindow::SetEventCallback(const EventCallbackFn &callback)
{
  m_Callback = callback;
  [(WindowDelegate *)m_Delegate setEventCallback: callback];
  ((CocoaContext *) m_Context)->SetCallback(callback);
}

void CocoaWindow::Show() {
  [(NSWindow *)m_Object makeKeyAndOrderFront: nil];
  [(NSWindow *)m_Object makeMainWindow];
  m_Open = true;  
}

} // namespace Apollo