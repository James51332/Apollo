#define APOLLO_OBJC_PLUS_PLUS
#include "CocoaApplication.h"

#include <Cocoa/Cocoa.h>

namespace Apollo {

CocoaApplication::CocoaApplication() 
{
  m_App = (void *)[NSApplication sharedApplication];
  [(NSApplication *)m_App setActivationPolicy: NSApplicationActivationPolicyRegular];

  // TODO: Create Proper Menu Bar

  // Credit to https://shiftedbits.org/2008/10/01/mach_absolute_time-on-the-iphone/
  // we need to store this to convert from mach units to nanoseconds (or any other standard time)
  mach_timebase_info(&m_TimeInfo);
}

CocoaApplication::~CocoaApplication() 
{

}

void CocoaApplication::Update() 
{
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

void CocoaApplication::Terminate() 
{
  [(NSApplication *)m_App terminate: nil];
}

float CocoaApplication::GetTime()
{
  double time = mach_absolute_time();

  // Convert to nanoseconds
  time *= m_TimeInfo.numer;
  time /= m_TimeInfo.denom;

  // Convert to seconds
  time /= 1000 * 1000 * 1000;

  return time;
}

} // namespace Apollo
