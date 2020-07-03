#include "Window.h"

#include "Platform/Cocoa/CocoaWindow.h"

namespace Apollo
{

  Window *Window::Create(const WindowDescription &desc)
  {
#ifdef APOLLO_COCOA
    CocoaWindow *window = new CocoaWindow(desc);
    window->SetContext(RenderingContext::Create(desc.ContextApi));
    return window;
#else
    return nullptr;
#endif
  }

  Window::~Window()
  {
  }

} // namespace Apollo
