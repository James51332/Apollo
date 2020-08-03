#define APOLLO_OBJC_PLUS_PLUS
#include "CocoaWindow.h"

#include "CocoaWindowDelegate.h"
#include "CocoaContext.h"

namespace Apollo {

CocoaWindow::CocoaWindow(const WindowDescription &desc) 
{
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
  
  m_Delegate = [[CocoaWindowDelegate alloc] init];
  [(NSWindow *)m_Object setDelegate: (CocoaWindowDelegate *) m_Delegate];
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
}

void CocoaWindow::Update() 
{
  m_Context->Update();
}

void CocoaWindow::Close()
{
  [(NSWindow *)m_Object close];
}

void CocoaWindow::SetEventCallback(const Window::WindowEventFn &callback)
{
  m_Callback = callback;
  
  [(CocoaWindowDelegate *)m_Delegate setEventCallback: callback];

  if (m_Context != nullptr)
    ((CocoaContext *)m_Context)->SetEventCallback(callback);
}

void CocoaWindow::SetContext(RenderingContext *context) 
{
  m_Context = context;

  ((CocoaContext *) context)->SetWindow(m_Object);
}

void CocoaWindow::SetDesc(const WindowDescription &desc) {
  NSRect frameRect = [(NSWindow *)m_Object frame];
  int contentHeight = [(NSWindow *)m_Object contentRectForFrameRect: frameRect].size.height;
  int titlebarHeight = frameRect.size.height - contentHeight;

  [(NSWindow *)m_Object setFrame: NSMakeRect(0.0, 0.0, desc.Width, desc.Height + titlebarHeight)
                         display: NO];
                      
  [(NSWindow *)m_Object center];
  [(NSWindow *)m_Object setTitle: @(desc.Title.c_str())];
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
