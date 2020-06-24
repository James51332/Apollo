#include "Window.h"

#include "Platform/Cocoa/CocoaWindow.h"

namespace Apollo
{

  Window *Window::Create(const WindowDescription &desc)
  {
    return new CocoaWindow(desc);
  }

  Window::~Window()
  {
  }

} // namespace Apollo
