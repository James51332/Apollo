#include "CocoaApplication.h"

#include <Cocoa/Cocoa.h>

namespace Apollo {

CocoaApplication::CocoaApplication() {
  m_App = (void *)[NSApplication sharedApplication];
}

CocoaApplication::~CocoaApplication() {

}

void CocoaApplication::Update() {
  for (;;) {
    NSEvent *event = [(NSApplication *)m_App nextEventMatchingMask: NSEventMaskAny
                                                                 untilDate: [NSDate distantPast]
                                                                    inMode: NSDefaultRunLoopMode
                                                                   dequeue: YES];
    
    if (!event)
      break;
    [(NSApplication *)m_App sendEvent: event];
    [event release];
  }
}

void CocoaApplication::Terminate() {
  [(NSApplication *)m_App terminate: nil];
}

} // namespace Apollo