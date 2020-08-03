#define APOLLO_OBJC_PLUS_PLUS
#include "CocoaView.h"

#include "CocoaInput.h"

#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

@implementation CocoaView 

- (instancetype) init
{
  if (self = [super initWithFrame: NSMakeRect(0.0, 0.0, 800.0, 600.0)])
  {
    m_ModifierFlags = 0;

    Apollo::CocoaInitKeyCodes(m_KeyCodes);

    return self;
  }

  return NULL;
}

- (void) setEventCallback: (const Apollo::Window::WindowEventFn &) callback
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
  Apollo::KeyPressedEvent e(m_KeyCodes[[event keyCode]], 0);

  if (m_Callback)
    m_Callback(e);
}

- (void) keyUp:(NSEvent *) event
{
  Apollo::KeyReleasedEvent e(m_KeyCodes[[event keyCode]]);

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
