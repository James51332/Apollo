#include "Window.h"

#include "Cocoa/CocoaWindow.h"

namespace Apollo
{

  Scope<Window> Window::Create(const WindowDescription &desc)
  {
    Scope<Window> window;

#ifdef APOLLO_MACOS
    window.reset(new CocoaWindow(desc));
    window->SetContext(RenderingContext::Create(desc.ContextApi));
#endif

    return window;
  }

  Window::~Window()
  {
  }

} // namespace Apollo
