#include "Window.h"

#include "Cocoa/CocoaWindow.h"

namespace Apollo
{

  Window *Window::Create(const WindowDescription &desc)
  {
#ifdef APOLLO_MACOS
    CocoaWindow *window = new CocoaWindow(desc);
    window->SetContext(RenderingContext::Create(desc.ContextApi));
    return window;
#endif

    return nullptr;
  }

  Window::~Window()
  {
  }

} // namespace Apollo
