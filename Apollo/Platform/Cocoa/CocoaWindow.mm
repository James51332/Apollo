#include "CocoaWindow.h"

#include <Cocoa/Cocoa.h>

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

  [(NSWindow *)m_Object makeKeyAndOrderFront: nil];
  [(NSWindow *)m_Object makeMainWindow];
  m_Open = true;
}

CocoaWindow::~CocoaWindow() {
  [(NSWindow *)m_Object release];
  m_Object = nullptr;
}

void CocoaWindow::Update() {
  //TODO: Update Context
}

} // namespace Apollo