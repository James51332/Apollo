#ifndef CocoaWindow_h
#define CocoaWindow_h

#include "Application/Window.h"

namespace Apollo
{

  class CocoaWindow : public Window
  {
  public:
    CocoaWindow(const WindowDescription &desc = WindowDescription());
    ~CocoaWindow();

    void Update();
    void SetContext(RenderingContext *context);

    int GetWidth();
    int GetHeight();

    void SetDesc(const WindowDescription &desc);
    void Show();

    void SetEventCallback(const EventCallbackFn &callback);

  private:
    void *m_Object;
    void *m_Delegate;
  };

} // namespace Apollo

#endif /* end of include guard: CocoaWindow_h */