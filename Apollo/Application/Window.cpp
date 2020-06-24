#include "Window.h"

#include "Platform/Cocoa/CocoaWindow.h"

namespace Apollo
{

  Window *Window::Create(const WindowDescription &desc)
  {
    CocoaWindow *window = new CocoaWindow(desc);
    window->SetContext(RenderingContext::Create(desc.ContextApi));
    return window;
  }

  Window::~Window()
  {
  }

} // namespace Apollo
