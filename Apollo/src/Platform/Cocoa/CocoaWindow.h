#ifndef CocoaWindow_h
#define CocoaWindow_h

#include "Core/Window.h"

namespace Apollo
{

  class CocoaWindow : public Window
  {
  public:
    CocoaWindow(const WindowDescription &desc);
    ~CocoaWindow();

    void Show();
    void Update();

    void SetEventCallback(const Window::WindowEventFn &callback);
    void SetContext(RenderingContext *context);
    void SetDesc(const WindowDescription &desc);

    int GetWidth();
    int GetHeight();

  private:
    void *m_Object;
    void *m_Delegate;
  };

} // namespace Apollo

#endif /* end of include guard: CocoaWindow_h */
